<?php

/**
 * @file
 * The Pretty Printer class for PHP code.
 */

use PhpParser\Comment;
use PhpParser\Node;
use PhpParser\Node\Expr;
use PhpParser\Node\Stmt;
use PhpParser\PrettyPrinter\Standard;

/**
 * Pretty-prints code for Drupal coding standards and HTML output.
 *
 * This class overrides the standard PrettyPrinter class from the PhpParser
 * project, so that the output conforms more closely with the Drupal project
 * coding standards. Modifications:
 * - Indentation is 2 spaces instead of 4 spaces.
 * - In class and function declarations, the { is on the same line instead of
 *   the next line.
 * - There is a blank line before the closing } in class declarations.
 * - There is extra vertical whitespace between items and comments in a set
 *   of statements.
 * - Arrays are printed out multi-line instead of single-line, and comments are
 *   printed inside arrays.
 * - Individual single-line '//' comments are combined into blocks.
 *
 * @todo Also need to add HTML formatting for links.
 */
class ApiPrettyPrinter extends Standard {

  /**
   * Overrides basic statement printing.
   *
   * Modifications:
   * - Indentation is 2 spaces not 4.
   * - Extra vertical whitespace.
   */
  protected function pStmts(array $nodes, $indent = true) {
    $result = '';
    foreach ($nodes as $node) {
      $comments = $node->getAttribute('comments', array());
      if ($comments) {
        $result .= "\n\n" . $this->pComments($comments);
        if ($node instanceof Stmt\Nop) {
          continue;
        }
      }

      $result .= "\n" . $this->p($node) . ($node instanceof Expr ? ';' : '');
    }
    if ($indent) {
      // Indent two spaces.
      return preg_replace('~\n(?!$|' . $this->noIndentToken . ')~', "\n  ", $result);
    } else {
      return $result;
    }
  }

  /**
   * Overrides comment printing.
   *
   * Adjoining single-line '//' comments are combined into blocks together,
   * and there are empty lines between comment blocks.
   *
   * @param Comment[] $comments
   *   List of comments.
   *
   * @return string
   *   Reformatted text of comments.
   */
  protected function pComments(array $comments) {
    $formattedComments = [];
    $prevType = 'not a comment';
    foreach ($comments as $comment) {
      $thisType = $this->findCommentPrefix($comment);
      if ($thisType == '//' && $prevType == '//') {
        // Combine this single-line comment with the previous one.
        $formattedComments[count($formattedComments) - 1] .= "\n" . $comment->getReformattedText();
      }
      else {
        $formattedComments[] = $comment->getReformattedText();
      }
      $prevType = $thisType;
    }
    return implode("\n\n", $formattedComments);
  }

  /**
   * Figures out the comment prefix.
   *
   * @param Comment $comment
   *   Comment object.
   *
   * @return string
   *   '//' if this is a single-line comment, or /** or /* if it is a multi-
   *   line comment.
   */
  protected function findCommentPrefix(Comment $comment) {
    $text = trim(preg_replace('|\s|', ' ', $comment->getText()));
    if (!$text) {
      return '';
    }
    $tokens = explode(' ', $text);
    return $tokens[0];
  }

  /**
   * Pretty-prints an array of nodes, comma separated, on separate lines.
   *
   * @param Node[] $nodes
   *   Array of Nodes to be printed.
   * @param bool $comma_at_end
   *   (optional) TRUE (default) if there should be a comma at the end of the
   *   last element too.
   *
   * @return string
   *   Comma separated pretty printed nodes, with each on its own line,
   *   indented.
   */
  protected function pCommaSeparatedMultiLine(array $nodes, $comma_at_end = TRUE) {
    // Implode with commas and newlines.
    $result = $this->pImplode($nodes, ",\n");
    if ($comma_at_end && count($nodes)) {
      $result .= ',';
    }

    // Indent the whole thing.
    return '  ' . preg_replace('~\n(?!$|' . $this->noIndentToken . ')~', "\n  ", $result) . "\n";
  }

  /**
   * Overrides array printing to use multiple lines.
   *
   * @see self::pExprArrayItem
   */
  protected function pExpr_Array(Expr\Array_ $node) {
    $syntax = $node->getAttribute('kind',
      $this->options['shortArraySyntax'] ? Expr\Array_::KIND_SHORT : Expr\Array_::KIND_LONG);
    if ($syntax === Expr\Array_::KIND_SHORT) {
      return "[\n" . $this->pCommaSeparatedMultiLine($node->items) . "]";
    } else {
      return "array(\n" . $this->pCommaSeparatedMultiLine($node->items) . ")";
    }
  }

  /**
   * Overrides printing of array items to include comments.
   */
  protected function pExpr_ArrayItem(Expr\ArrayItem $node) {
    $result = '';
    $comments = $node->getAttribute('comments', array());
    if ($comments) {
      $result .= $this->pComments($comments) . "\n";
    }
    $result .= (null !== $node->key ? $this->p($node->key) . ' => ' : '')
      . ($node->byRef ? '&' : '') . $this->p($node->value);

    return $result;
  }

  /**
   * Overrides elseif printing to start on next line.
   */
  protected function pStmt_ElseIf(Stmt\ElseIf_ $node) {
    return "\n" . 'elseif (' . $this->p($node->cond) . ') {'
      . $this->pStmts($node->stmts) . "\n" . '}';
  }

  /**
   * Overrides else printing to start on next line.
   */
  protected function pStmt_Else(Stmt\Else_ $node) {
    return "\n" . 'else {' . $this->pStmts($node->stmts) . "\n" . '}';
  }

  /**
   * Overrides interface printing.
   *
   * Modifications:
   * - Put the { on the same line.
   * - Leave a blank line before the }.
   */
  protected function pStmt_Interface(Stmt\Interface_ $node) {
    return 'interface ' . $node->name
      . (!empty($node->extends) ? ' extends ' . $this->pCommaSeparated($node->extends) : '')
      . ' {' . $this->pStmts($node->stmts) . "\n\n" . '}';
  }

  /**
   * Overrides trait printing.
   *
   * Modifications:
   * - Put the { on the same line.
   * - Leave a blank line before the }.
   */
  protected function pStmt_Trait(Stmt\Trait_ $node) {
    return 'trait ' . $node->name
      . ' {' . $this->pStmts($node->stmts) . "\n\n" . '}';
  }

  /**
   * Overrides class printing.
   *
   * Modifications:
   * - Put the { on the same line.
   * - Leave a blank line before the }.
   */
  protected function pClassCommon(Stmt\Class_ $node, $afterClassToken) {
    return $this->pModifiers($node->flags)
      . 'class' . $afterClassToken
      . (null !== $node->extends ? ' extends ' . $this->p($node->extends) : '')
      . (!empty($node->implements) ? ' implements ' . $this->pCommaSeparated($node->implements) : '')
      . ' {' . $this->pStmts($node->stmts) . "\n\n" . '}';
  }

  /**
   * Overrides function printing to put the { on the same line.
   */
  protected function pStmt_Function(Stmt\Function_ $node) {
    return 'function ' . ($node->byRef ? '&' : '') . $node->name
      . '(' . $this->pCommaSeparated($node->params) . ')'
      . (null !== $node->returnType ? ' : ' . $this->pType($node->returnType) : '')
      . ' {' . $this->pStmts($node->stmts) . "\n" . '}';
  }

  /**
   * Overrides class method printing to put the { on the same line.
   */
  protected function pStmt_ClassMethod(Stmt\ClassMethod $node) {
    return $this->pModifiers($node->flags)
      . 'function ' . ($node->byRef ? '&' : '') . $node->name
      . '(' . $this->pCommaSeparated($node->params) . ')'
      . (null !== $node->returnType ? ' : ' . $this->pType($node->returnType) : '')
      . (null !== $node->stmts
        ? ' {' . $this->pStmts($node->stmts) . "\n" . '}'
        : ';');
    }


  /**
   * Overrides closure printing.
   *
   * Overrides:
   * - Space between use and the use statements.
   */
  protected function pExpr_Closure(Expr\Closure $node) {
    return ($node->static ? 'static ' : '')
      . 'function ' . ($node->byRef ? '&' : '')
      . '(' . $this->pCommaSeparated($node->params) . ')'
      . (!empty($node->uses) ? ' use (' . $this->pCommaSeparated($node->uses) . ')': '')
      . (null !== $node->returnType ? ' : ' . $this->pType($node->returnType) : '')
      . ' {' . $this->pStmts($node->stmts) . "\n" . '}';
  }

}
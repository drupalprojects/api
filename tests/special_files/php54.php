<?php

/**
 * @file
 * Tests some PHP 5.4 features.
 */

/**
 * Tests that PHP 5.4 array syntax can be parsed and displayed.
 */
function array_5_4() {
  // For testing PHP 5.4 array syntax.
  $foo = [
    'href' => 'bar',
    [[ 'nested' => 'valid']],
  ];
}

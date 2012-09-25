<?php
/**
 * Views integration for the API module.
 */

// @todo: Filters for the various types of references would be killer.

/**
 * Implements hook_views_data().
 *
 * Defines the base data table for making Views of API documentation items.
 */
function api_views_data() {
  $data = array();

  $data['api_documentation'] = array(
    'table' => array(
      'group' => t('API documentation'),
      'base' => array(
        'field' => 'did',
        'title' => t('API documentation'),
        'help' => t('Documentation objects from the API module (representing functions, classes, etc.)'),
        'weight' => 20,
      ),
    ),

    'did' => array(
      'title' => t('Documentation ID'),
      'relationship' => array(
        'base' => 'comment',
        'base field' => 'nid',
        'handler' => 'views_handler_relationship',
        'label' => t('Comments'),
        'title' => t('All comments'),
        'help' => t('All comments on this documentation object. This will create duplicate records, so you probably want a comment view instead.'),
      ),
    ),

    'branch_id' => array(
      'title' => t('Branch'),
      'relationship' => array(
        'base' => 'api_branch',
        'handler' => 'views_handler_relationship',
        'label' => t('Branch'),
        'title' => t('Branch'),
        'help' => t('The branch this documentation is in'),
      ),
    ),

    'object_name' => array(
      'title' => t('Object name'),
      'help' => t('Name of this object'),
      'field' => array(
        'handler' => 'api_views_handler_field_api_linkable',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'title' => array(
      'title' => t('Title'),
      'help' => t('Title of this object'),
      'field' => array(
        'handler' => 'api_views_handler_field_api_linkable',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'member_name' => array(
      'title' => t('Member name'),
      'help' => t('For class members, the name without the Class:: prefix; for others, blank.'),
      'field' => array(
        'handler' => 'api_views_handler_field_api_linkable',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),

    'class_did' => array(
      'title' => t('Class documentation ID'),
      'help' => t('Class ID'),
      'relationship' => array(
        'base' => 'api_documentation',
        'base field' => 'did',
        'handler' => 'views_handler_relationship',
        'label' => t('Class object'),
        'title' => t('Class object'),
        'help' => t('The documentation object for the class this object is a member of'),
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
    ),

    'summary' => array(
      'title' => t('Summary'),
      'help' => t('One-line summary of documentation'),
      'field' => array(
        'handler' => 'api_views_handler_field_api_docs',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'object_type' => array(
      'title' => t('Object type'),
      'help' => t('Type of this object (file, function, etc.)'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),

    'file_name' => array(
      'title' => t('File name'),
      'help' => t('File this object is in, relative to branch directory'),
      'field' => array(
        'handler' => 'api_views_handler_field_api_linkable',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'start_line' => array(
      'title' => t('Start line'),
      'help' => t('Starting line of the code within the file'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    ),

  );

  $data['api_branch'] = array(
    'table' => array(
      'group' => t('API documentation'),
      'base' => array(
        'field' => 'branch_id',
        'title' => t('API branch'),
        'help' => t('Branches from the API module'),
        'weight' => 21,
      ),
    ),

    'branch_id' => array(
      'title' => t('Branch ID'),
      'relationship' => array(
        'base' => 'api_documentation',
        'handler' => 'views_handler_relationship',
        'label' => t('Documentation objects'),
        'title' => t('All documentation objects'),
        'help' => t('All documentation objects in this branch. This will create duplicate records, so you probably want a documentation view instead.'),
      ),
    ),

    'branch_name' => array(
      'title' => t('Branch name'),
      'help' => t('Short name of this branch, within the project'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'title' => array(
      'title' => t('Branch title'),
      'help' => t('Displayed name of this branch, including the project'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),

    'core_compatibility' => array(
      'title' => t('Core compatibility'),
      'help' => t('Which core version this branch is compatible with'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'project' => array(
      'title' => t('Project'),
      'relationship' => array(
        'base' => 'api_project',
        'handler' => 'views_handler_relationship',
        'label' => t('Project'),
        'title' => t('Project'),
        'help' => t('The project this branch is part of'),
      ),
    ),
  );

  $data['api_project'] = array(
    'table' => array(
      'group' => t('API project'),
      'base' => array(
        'field' => 'project_name',
        'title' => t('API project'),
        'help' => t('Projects from the API module'),
        'weight' => 22,
      ),
    ),

    'project_name' => array(
      'title' => t('Project name'),
      'help' => t('Short name of the project'),
      'relationship' => array(
        'base' => 'api_branch',
        'handler' => 'views_handler_relationship',
        'label' => t('Documentation branches'),
        'title' => t('All documentation branches'),
        'help' => t('All documentation branches in this project. This will create duplicate records, so you probably want a documentation or branch view instead.'),
      ),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),

    'project_title' => array(
      'title' => t('Project title'),
      'help' => t('Long, human-readable name of the project'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
    ),

    'project_type' => array(
      'title' => t('Project type'),
      'help' => t('Type of project: module, theme, core, etc.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 *
 * Adds a relationship to the Comment table and the comment statistics.
 */
function api_views_data_alter(&$data) {
  $data['comment']['did'] = array(
    'title' => t('Documentation ID'),
    'help' => t('The ID of the documentation object the comment is a reply to.'),
    'relationship' => array(
      'base' => 'api_documentation',
      'base field' => 'did',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('API documentation object'),
      'title' => t('API documentation object'),
      'help' => t('The ID of the documentation object the comment is a reply to.'),
    ),
  );

  $data['node_comment_statistics']['table']['join']['api_documentation'] = array(
    'type' => 'INNER',
    'left_field' => 'did',
    'field' => 'nid',
  );
}

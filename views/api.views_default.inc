<?php

/**
 * Default views for the API module, for lists of documentation items.
 */

/**
 * Implements hook_views_default_views().
 *
 * Defines the following views:
 * - api_listings: Generates the API listing pages.
 * - api_projects: Generates the Projects page.
 * - api_branches: Generates the Branch admin page.
 */
function api_views_default_views() {
  $views = array();

  // API Listings view.
  $view = new view();
  $view->name = 'api_listings';
  $view->description = 'Blocks for listing API documentation items. Used directly by the API module. Do not delete or disable.';
  $view->tag = 'default';
  $view->base_table = 'api_documentation';
  $view->human_name = 'API Listings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access API reference';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'file_name' => 'file_name',
    'summary' => 'summary',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'file_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: API documentation: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_docs'] = 'object';
  /* Field: API documentation: File name */
  $handler->display->display_options['fields']['file_name']['id'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['file_name']['field'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['label'] = 'Location';
  $handler->display->display_options['fields']['file_name']['link_to_docs'] = 'file_base';
  /* Field: API documentation: Summary */
  $handler->display->display_options['fields']['summary']['id'] = 'summary';
  $handler->display->display_options['fields']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['summary']['field'] = 'summary';
  $handler->display->display_options['fields']['summary']['label'] = 'Description';
  /* Sort criterion: API documentation: Object name */
  $handler->display->display_options['sorts']['object_name']['id'] = 'object_name';
  $handler->display->display_options['sorts']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['sorts']['object_name']['field'] = 'object_name';
  /* Contextual filter: API documentation: Object type */
  $handler->display->display_options['arguments']['object_type']['id'] = 'object_type';
  $handler->display->display_options['arguments']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['object_type']['field'] = 'object_type';
  $handler->display->display_options['arguments']['object_type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['object_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['object_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['object_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['object_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['object_type']['limit'] = '0';
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';

  /* Display: Default Listing Block */
  $handler = $view->new_display('block', 'Default Listing Block', 'block_listing');
  $handler->display->display_options['display_description'] = 'Block for listing functions, constants, etc.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Class documentation ID */
  $handler->display->display_options['filters']['class_did']['id'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['class_did']['field'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['value']['value'] = '0';
  /* Filter criterion: API documentation: Object name */
  $handler->display->display_options['filters']['object_name']['id'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_name']['field'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['object_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['object_name']['expose']['operator_id'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['label'] = 'Name contains';
  $handler->display->display_options['filters']['object_name']['expose']['description'] = 'Contains filters are case sensitive';
  $handler->display->display_options['filters']['object_name']['expose']['operator'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['identifier'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Summary */
  $handler->display->display_options['filters']['summary']['id'] = 'summary';
  $handler->display->display_options['filters']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['summary']['field'] = 'summary';
  $handler->display->display_options['filters']['summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['summary']['expose']['operator_id'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['label'] = 'Description contains';
  $handler->display->display_options['filters']['summary']['expose']['operator'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['identifier'] = 'summary';
  $handler->display->display_options['filters']['summary']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['block_description'] = 'API documentation item listing';

  /* Display: File Listing Block */
  $handler = $view->new_display('block', 'File Listing Block', 'block_files');
  $handler->display->display_options['display_description'] = 'Block for listing files';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'object_name' => 'object_name',
    'namespace' => 'namespace',
    'summary' => 'summary',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'object_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'namespace' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API documentation: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'File name';
  /* Field: API documentation: Object name */
  $handler->display->display_options['fields']['object_name']['id'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['object_name']['field'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['label'] = 'Location';
  $handler->display->display_options['fields']['object_name']['link_to_docs'] = 'object';
  /* Field: API documentation: Namespace */
  $handler->display->display_options['fields']['namespace']['id'] = 'namespace';
  $handler->display->display_options['fields']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['namespace']['field'] = 'namespace';
  /* Field: API documentation: Summary */
  $handler->display->display_options['fields']['summary']['id'] = 'summary';
  $handler->display->display_options['fields']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['summary']['field'] = 'summary';
  $handler->display->display_options['fields']['summary']['label'] = 'Description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type']['id'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['value'] = 'file';
  $handler->display->display_options['filters']['object_type']['group'] = 1;
  /* Filter criterion: API documentation: Object name */
  $handler->display->display_options['filters']['object_name']['id'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_name']['field'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['object_name']['group'] = 1;
  $handler->display->display_options['filters']['object_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['object_name']['expose']['operator_id'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['label'] = 'Location contains';
  $handler->display->display_options['filters']['object_name']['expose']['description'] = 'Contains filters are case sensitive';
  $handler->display->display_options['filters']['object_name']['expose']['operator'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['identifier'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Namespace */
  $handler->display->display_options['filters']['namespace']['id'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['namespace']['field'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['operator'] = 'contains';
  $handler->display->display_options['filters']['namespace']['group'] = 1;
  $handler->display->display_options['filters']['namespace']['exposed'] = TRUE;
  $handler->display->display_options['filters']['namespace']['expose']['operator_id'] = 'namespace_op';
  $handler->display->display_options['filters']['namespace']['expose']['label'] = 'Namespace contains';
  $handler->display->display_options['filters']['namespace']['expose']['operator'] = 'namespace_op';
  $handler->display->display_options['filters']['namespace']['expose']['identifier'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Summary */
  $handler->display->display_options['filters']['summary']['id'] = 'summary';
  $handler->display->display_options['filters']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['summary']['field'] = 'summary';
  $handler->display->display_options['filters']['summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['summary']['group'] = 1;
  $handler->display->display_options['filters']['summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['summary']['expose']['operator_id'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['label'] = 'Description contains';
  $handler->display->display_options['filters']['summary']['expose']['operator'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['identifier'] = 'summary';
  $handler->display->display_options['filters']['summary']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['block_description'] = 'API documentation file listing';

  /* Display: Class Listing Block */
  $handler = $view->new_display('block', 'Class Listing Block', 'block_class');
  $handler->display->display_options['display_description'] = 'Block for listing classes and interfaces';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'object_name' => 'object_name',
    'namespace' => 'namespace',
    'file_name' => 'file_name',
    'summary' => 'summary',
  );
  $handler->display->display_options['style_options']['default'] = 'object_name';
  $handler->display->display_options['style_options']['info'] = array(
    'object_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'namespace' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'file_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API documentation: Object name */
  $handler->display->display_options['fields']['object_name']['id'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['object_name']['field'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['label'] = 'Name';
  $handler->display->display_options['fields']['object_name']['link_to_docs'] = 'object';
  /* Field: API documentation: Namespace */
  $handler->display->display_options['fields']['namespace']['id'] = 'namespace';
  $handler->display->display_options['fields']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['namespace']['field'] = 'namespace';
  /* Field: API documentation: File name */
  $handler->display->display_options['fields']['file_name']['id'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['file_name']['field'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['label'] = 'Location';
  $handler->display->display_options['fields']['file_name']['link_to_docs'] = 'file_base';
  /* Field: API documentation: Summary */
  $handler->display->display_options['fields']['summary']['id'] = 'summary';
  $handler->display->display_options['fields']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['summary']['field'] = 'summary';
  $handler->display->display_options['fields']['summary']['label'] = 'Description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Class documentation ID */
  $handler->display->display_options['filters']['class_did']['id'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['class_did']['field'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['value']['value'] = '0';
  $handler->display->display_options['filters']['class_did']['group'] = 1;
  /* Filter criterion: API documentation: Object name */
  $handler->display->display_options['filters']['object_name']['id'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_name']['field'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['object_name']['group'] = 1;
  $handler->display->display_options['filters']['object_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['object_name']['expose']['operator_id'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['label'] = 'Name contains';
  $handler->display->display_options['filters']['object_name']['expose']['description'] = 'Contains filters are case sensitive';
  $handler->display->display_options['filters']['object_name']['expose']['operator'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['identifier'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Namespace */
  $handler->display->display_options['filters']['namespace']['id'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['namespace']['field'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['operator'] = 'contains';
  $handler->display->display_options['filters']['namespace']['group'] = 1;
  $handler->display->display_options['filters']['namespace']['exposed'] = TRUE;
  $handler->display->display_options['filters']['namespace']['expose']['operator_id'] = 'namespace_op';
  $handler->display->display_options['filters']['namespace']['expose']['label'] = 'Namespace contains';
  $handler->display->display_options['filters']['namespace']['expose']['operator'] = 'namespace_op';
  $handler->display->display_options['filters']['namespace']['expose']['identifier'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Summary */
  $handler->display->display_options['filters']['summary']['id'] = 'summary';
  $handler->display->display_options['filters']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['summary']['field'] = 'summary';
  $handler->display->display_options['filters']['summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['summary']['group'] = 1;
  $handler->display->display_options['filters']['summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['summary']['expose']['operator_id'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['label'] = 'Description contains';
  $handler->display->display_options['filters']['summary']['expose']['operator'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['identifier'] = 'summary';
  $handler->display->display_options['filters']['summary']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type']['id'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['value'] = 'class';
  $handler->display->display_options['filters']['object_type']['group'] = 2;
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type_1']['id'] = 'object_type_1';
  $handler->display->display_options['filters']['object_type_1']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type_1']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type_1']['value'] = 'interface';
  $handler->display->display_options['filters']['object_type_1']['group'] = 2;
  $handler->display->display_options['block_description'] = 'API documentation class listing';

  /* Display: Topic Listing Block */
  $handler = $view->new_display('block', 'Topic Listing Block', 'block_groups');
  $handler->display->display_options['display_description'] = 'Block for listing groups/topics';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'summary' => 'summary',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'summary' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API documentation: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_docs'] = 'object';
  /* Field: API documentation: Summary */
  $handler->display->display_options['fields']['summary']['id'] = 'summary';
  $handler->display->display_options['fields']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['summary']['field'] = 'summary';
  $handler->display->display_options['fields']['summary']['label'] = 'Description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Class documentation ID */
  $handler->display->display_options['filters']['class_did']['id'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['class_did']['field'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['value']['value'] = '0';
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type']['id'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['value'] = 'group';
  /* Filter criterion: API documentation: Object name */
  $handler->display->display_options['filters']['object_name']['id'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_name']['field'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['operator'] = 'contains';
  $handler->display->display_options['filters']['object_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['object_name']['expose']['operator_id'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['label'] = 'Name contains';
  $handler->display->display_options['filters']['object_name']['expose']['description'] = 'Contains filters are case sensitve';
  $handler->display->display_options['filters']['object_name']['expose']['operator'] = 'object_name_op';
  $handler->display->display_options['filters']['object_name']['expose']['identifier'] = 'object_name';
  $handler->display->display_options['filters']['object_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: API documentation: Summary */
  $handler->display->display_options['filters']['summary']['id'] = 'summary';
  $handler->display->display_options['filters']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['summary']['field'] = 'summary';
  $handler->display->display_options['filters']['summary']['operator'] = 'contains';
  $handler->display->display_options['filters']['summary']['exposed'] = TRUE;
  $handler->display->display_options['filters']['summary']['expose']['operator_id'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['label'] = 'Description contains';
  $handler->display->display_options['filters']['summary']['expose']['operator'] = 'summary_op';
  $handler->display->display_options['filters']['summary']['expose']['identifier'] = 'summary';
  $handler->display->display_options['filters']['summary']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['block_description'] = 'API documentation topic listing';

  /* Display: Items in file block */
  $handler = $view->new_display('block', 'Items in file block', 'block_items_file');
  $handler->display->display_options['display_description'] = 'Block for listing functions, constants, etc. in a particular file';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API documentation: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['link_to_docs'] = 'object';
  /* Field: API documentation: Summary */
  $handler->display->display_options['fields']['summary']['id'] = 'summary';
  $handler->display->display_options['fields']['summary']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['summary']['field'] = 'summary';
  $handler->display->display_options['fields']['summary']['label'] = 'Description';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: API documentation: File name */
  $handler->display->display_options['arguments']['file_name']['id'] = 'file_name';
  $handler->display->display_options['arguments']['file_name']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['file_name']['field'] = 'file_name';
  $handler->display->display_options['arguments']['file_name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['file_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['file_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['file_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['file_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['file_name']['limit'] = '0';
  /* Contextual filter: API documentation: Object type */
  $handler->display->display_options['arguments']['object_type']['id'] = 'object_type';
  $handler->display->display_options['arguments']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['object_type']['field'] = 'object_type';
  $handler->display->display_options['arguments']['object_type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['object_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['object_type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['object_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['object_type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['object_type']['limit'] = '0';
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Class documentation ID */
  $handler->display->display_options['filters']['class_did']['id'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['class_did']['field'] = 'class_did';
  $handler->display->display_options['filters']['class_did']['value']['value'] = '0';
  $handler->display->display_options['block_description'] = 'API documentation items in file listing';

  $views[$view->name] = $view;


  // API Projects view.
  $view = new view();
  $view->name = 'api_projects';
  $view->description = 'Blocks for listing projects in the API module. Used directly by the API module. Do not delete or disable.';
  $view->tag = 'default';
  $view->base_table = 'api_project';
  $view->human_name = 'API Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'API Projects';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access API reference';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: API project: Project title */
  $handler->display->display_options['fields']['project_title']['id'] = 'project_title';
  $handler->display->display_options['fields']['project_title']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_title']['field'] = 'project_title';
  $handler->display->display_options['fields']['project_title']['label'] = '';
  $handler->display->display_options['fields']['project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['project_title']['link_to_project'] = 'project';
  /* Sort criterion: API project: Project title */
  $handler->display->display_options['sorts']['project_title']['id'] = 'project_title';
  $handler->display->display_options['sorts']['project_title']['table'] = 'api_project';
  $handler->display->display_options['sorts']['project_title']['field'] = 'project_title';

  /* Display: Project list */
  $handler = $view->new_display('block', 'Project list', 'block_project_list');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'api-project-links';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Project admin */
  $handler = $view->new_display('block', 'Project admin', 'block_project_admin');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer API reference';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'project_name' => 'project_name',
    'project_title' => 'project_title',
    'project_type' => 'project_type',
  );
  $handler->display->display_options['style_options']['default'] = 'project_name';
  $handler->display->display_options['style_options']['info'] = array(
    'project_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'project_title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'project_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No matches';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No projects match your filters.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API project: Project name */
  $handler->display->display_options['fields']['project_name']['id'] = 'project_name';
  $handler->display->display_options['fields']['project_name']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_name']['field'] = 'project_name';
  $handler->display->display_options['fields']['project_name']['label'] = 'Project identifier';
  /* Field: API project: Project title */
  $handler->display->display_options['fields']['project_title']['id'] = 'project_title';
  $handler->display->display_options['fields']['project_title']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_title']['field'] = 'project_title';
  $handler->display->display_options['fields']['project_title']['label'] = 'Title';
  $handler->display->display_options['fields']['project_title']['element_label_colon'] = FALSE;
  /* Field: API project: Project type */
  $handler->display->display_options['fields']['project_type']['id'] = 'project_type';
  $handler->display->display_options['fields']['project_type']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_type']['field'] = 'project_type';
  $handler->display->display_options['fields']['project_type']['label'] = 'Type';
  /* Field: API project: Project operations */
  $handler->display->display_options['fields']['project_ops']['id'] = 'project_ops';
  $handler->display->display_options['fields']['project_ops']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_ops']['field'] = 'project_ops';
  $handler->display->display_options['fields']['project_ops']['label'] = 'Operations';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: API project: Project title */
  $handler->display->display_options['sorts']['project_title']['id'] = 'project_title';
  $handler->display->display_options['sorts']['project_title']['table'] = 'api_project';
  $handler->display->display_options['sorts']['project_title']['field'] = 'project_title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API project: Project type */
  $handler->display->display_options['filters']['project_type']['id'] = 'project_type';
  $handler->display->display_options['filters']['project_type']['table'] = 'api_project';
  $handler->display->display_options['filters']['project_type']['field'] = 'project_type';
  $handler->display->display_options['filters']['project_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['project_type']['expose']['operator_id'] = 'project_type_op';
  $handler->display->display_options['filters']['project_type']['expose']['label'] = 'Filter by project type';
  $handler->display->display_options['filters']['project_type']['expose']['operator'] = 'project_type_op';
  $handler->display->display_options['filters']['project_type']['expose']['identifier'] = 'project_type';
  $handler->display->display_options['filters']['project_type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['project_type']['group_info']['label'] = 'Project type';
  $handler->display->display_options['filters']['project_type']['group_info']['identifier'] = 'project_type';
  $handler->display->display_options['filters']['project_type']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['project_type']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );

  $views[$view->name] = $view;

  // API Branches view.

  $view = new view();
  $view->name = 'api_branches';
  $view->description = 'Blocks for listing branches in the API module. Used directly by the API module. Do not delete or disable.';
  $view->tag = 'default';
  $view->base_table = 'api_branch';
  $view->human_name = 'API Branches';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'API Branches';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer API reference';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'project_name' => 'project_name',
    'core_compatibility' => 'core_compatibility',
    'title' => 'title',
    'branch_name' => 'branch_name',
  );
  $handler->display->display_options['style_options']['default'] = 'project_name';
  $handler->display->display_options['style_options']['info'] = array(
    'project_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'core_compatibility' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'branch_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: API documentation: Project */
  $handler->display->display_options['relationships']['project']['id'] = 'project';
  $handler->display->display_options['relationships']['project']['table'] = 'api_branch';
  $handler->display->display_options['relationships']['project']['field'] = 'project';
  $handler->display->display_options['relationships']['project']['required'] = TRUE;
  /* Field: API project: Project name */
  $handler->display->display_options['fields']['project_name']['id'] = 'project_name';
  $handler->display->display_options['fields']['project_name']['table'] = 'api_project';
  $handler->display->display_options['fields']['project_name']['field'] = 'project_name';
  $handler->display->display_options['fields']['project_name']['relationship'] = 'project';
  $handler->display->display_options['fields']['project_name']['label'] = 'Project';
  /* Field: API documentation: Core compatibility */
  $handler->display->display_options['fields']['core_compatibility']['id'] = 'core_compatibility';
  $handler->display->display_options['fields']['core_compatibility']['table'] = 'api_branch';
  $handler->display->display_options['fields']['core_compatibility']['field'] = 'core_compatibility';
  /* Field: API documentation: Branch title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'api_branch';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: API documentation: Branch name */
  $handler->display->display_options['fields']['branch_name']['id'] = 'branch_name';
  $handler->display->display_options['fields']['branch_name']['table'] = 'api_branch';
  $handler->display->display_options['fields']['branch_name']['field'] = 'branch_name';
  $handler->display->display_options['fields']['branch_name']['label'] = 'Branch identifier';
  /* Field: API documentation: Branch operations */
  $handler->display->display_options['fields']['branch_ops']['id'] = 'branch_ops';
  $handler->display->display_options['fields']['branch_ops']['table'] = 'api_branch';
  $handler->display->display_options['fields']['branch_ops']['field'] = 'branch_ops';
  $handler->display->display_options['fields']['branch_ops']['label'] = 'Operations';
  /* Filter criterion: API project: Project name */
  $handler->display->display_options['filters']['project_name']['id'] = 'project_name';
  $handler->display->display_options['filters']['project_name']['table'] = 'api_project';
  $handler->display->display_options['filters']['project_name']['field'] = 'project_name';
  $handler->display->display_options['filters']['project_name']['relationship'] = 'project';
  $handler->display->display_options['filters']['project_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['project_name']['expose']['operator_id'] = 'project_name_op';
  $handler->display->display_options['filters']['project_name']['expose']['label'] = 'Filter by project';
  $handler->display->display_options['filters']['project_name']['expose']['operator'] = 'project_name_op';
  $handler->display->display_options['filters']['project_name']['expose']['identifier'] = 'project_name';
  $handler->display->display_options['filters']['project_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_branch_admin');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;


  $views[$view->name] = $view;

  // Namespaces view.

  $view = new view();
  $view->name = 'api_namespaces';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'api_documentation';
  $view->human_name = 'API Namespaces';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'API Namespaces';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'object_name' => 'object_name',
    'file_name' => 'file_name',
  );
  $handler->display->display_options['style_options']['default'] = 'object_name';
  $handler->display->display_options['style_options']['info'] = array(
    'object_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'file_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: API documentation: Namespace */
  $handler->display->display_options['fields']['namespace']['id'] = 'namespace';
  $handler->display->display_options['fields']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['namespace']['field'] = 'namespace';
  $handler->display->display_options['fields']['namespace']['link_to_namespace'] = 'object';
  /* Sort criterion: API documentation: Namespace */
  $handler->display->display_options['sorts']['namespace']['id'] = 'namespace';
  $handler->display->display_options['sorts']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['sorts']['namespace']['field'] = 'namespace';
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: API documentation: Namespace */
  $handler->display->display_options['filters']['namespace']['id'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['namespace']['field'] = 'namespace';
  $handler->display->display_options['filters']['namespace']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['namespace']['value'] = '2';
  /* Filter criterion: API documentation: Namespace */
  $handler->display->display_options['filters']['namespace_1']['id'] = 'namespace_1';
  $handler->display->display_options['filters']['namespace_1']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['namespace_1']['field'] = 'namespace';
  $handler->display->display_options['filters']['namespace_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['namespace_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['namespace_1']['expose']['operator_id'] = 'namespace_1_op';
  $handler->display->display_options['filters']['namespace_1']['expose']['label'] = 'Namespace contains';
  $handler->display->display_options['filters']['namespace_1']['expose']['description'] = 'Contains filters are case sensitive';
  $handler->display->display_options['filters']['namespace_1']['expose']['operator'] = 'namespace_1_op';
  $handler->display->display_options['filters']['namespace_1']['expose']['identifier'] = 'namespace_1';
  $handler->display->display_options['filters']['namespace_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Namespace list */
  $handler = $view->new_display('block', 'Namespace list', 'block_namespace_list');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'API namespace list';

  /* Display: Namespace list of items */
  $handler = $view->new_display('block', 'Namespace list of items', 'block_items_namespace');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: API documentation: Object name */
  $handler->display->display_options['fields']['object_name']['id'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['object_name']['field'] = 'object_name';
  $handler->display->display_options['fields']['object_name']['label'] = 'Name';
  $handler->display->display_options['fields']['object_name']['link_to_docs'] = 'object';
  /* Field: API documentation: File name */
  $handler->display->display_options['fields']['file_name']['id'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['table'] = 'api_documentation';
  $handler->display->display_options['fields']['file_name']['field'] = 'file_name';
  $handler->display->display_options['fields']['file_name']['label'] = 'Location';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: API documentation: Object name */
  $handler->display->display_options['sorts']['object_name']['id'] = 'object_name';
  $handler->display->display_options['sorts']['object_name']['table'] = 'api_documentation';
  $handler->display->display_options['sorts']['object_name']['field'] = 'object_name';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: API documentation: Branch */
  $handler->display->display_options['arguments']['branch_id']['id'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['branch_id']['field'] = 'branch_id';
  $handler->display->display_options['arguments']['branch_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['branch_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['branch_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['branch_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['branch_id']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: API documentation: Namespace */
  $handler->display->display_options['arguments']['namespace']['id'] = 'namespace';
  $handler->display->display_options['arguments']['namespace']['table'] = 'api_documentation';
  $handler->display->display_options['arguments']['namespace']['field'] = 'namespace';
  $handler->display->display_options['arguments']['namespace']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['namespace']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['namespace']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['namespace']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['namespace']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['namespace']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type']['id'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type']['value'] = 'class';
  $handler->display->display_options['filters']['object_type']['group'] = 1;
  /* Filter criterion: API documentation: Object type */
  $handler->display->display_options['filters']['object_type_1']['id'] = 'object_type_1';
  $handler->display->display_options['filters']['object_type_1']['table'] = 'api_documentation';
  $handler->display->display_options['filters']['object_type_1']['field'] = 'object_type';
  $handler->display->display_options['filters']['object_type_1']['value'] = 'interface';
  $handler->display->display_options['filters']['object_type_1']['group'] = 1;
  $handler->display->display_options['block_description'] = 'API namespace item list';

  $views[$view->name] = $view;

  return $views;
}

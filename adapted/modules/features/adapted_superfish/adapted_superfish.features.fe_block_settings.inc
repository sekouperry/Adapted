<?php
/**
 * @file
 * adapted_superfish.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function adapted_superfish_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['superfish-1'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '1',
    'module' => 'superfish',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adaptivetheme' => array(
        'region' => 'menu_bar',
        'status' => '1',
        'theme' => 'adaptivetheme',
        'weight' => '0',
      ),
      'adaptivetheme_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adaptivetheme_admin',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '0',
  );

  return $export;
}


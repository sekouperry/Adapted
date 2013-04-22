<?php

function adapted_blocks_build() {

  // Setup some default blocks
  $theme = variable_get('theme_default', 'adaptivetheme');
  $values = array(
    array(
      'module' => 'system',
      'delta' => 'main',
      'theme' => $theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'content',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'user',
      'delta' => 'login',
      'theme' => $theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'sidebar_second',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'navigation',
      'theme' => $theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'sidebar_second',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'management',
      'theme' => $theme,
      'status' => 1,
      'weight' => 1,
      'region' => 'sidebar_second',
      'pages' => '',
      'cache' => -1,
    ),
    array(
      'module' => 'system',
      'delta' => 'help',
      'theme' => $theme,
      'status' => 1,
      'weight' => 0,
      'region' => 'help',
      'pages' => '',
      'cache' => -1,
    ),
  );
  $query = db_insert('block')->fields(array('module', 'delta', 'theme', 'status', 'weight', 'region', 'pages', 'cache'));
  foreach ($values as $record) {
    $query->values($record);
  }
  $query->execute();

}

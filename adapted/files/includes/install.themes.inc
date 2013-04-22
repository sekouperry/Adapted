<?php

function adapted_themes_build() {

  // set the default theme
  $theme = 'at_panels_everywhere';
  theme_enable(array($theme));
  variable_set('theme_default', $theme);

  // set the admin theme
  $admin_theme = 'ember';
  theme_enable(array($admin_theme));
  variable_set('admin_theme', $admin_theme);

  // set the node admin theme
  variable_set('node_admin_theme', 1);

  // Disable the default Bartik theme.
  theme_disable(array('bartik'));

  // Flush theme caches so things are right
  system_rebuild_theme_data();
  drupal_theme_rebuild();

}

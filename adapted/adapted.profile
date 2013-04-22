<?php

/**
 * Implements hook_install_tasks()
 */
function adapted_install_tasks(&$install_state) {

  $tasks = array();

  // Add our custom CSS file for the installation process
  drupal_add_css(drupal_get_path('profile', 'adapted') . '/files/css/adapted.css');
  drupal_add_css(drupal_get_path('profile', 'adapted') . '/files/css/darkie.css');

  // Add the Panopoly app selection to the installation process
  // require_once(drupal_get_path('module', 'apps') . '/apps.profile.inc');
  // $tasks = $tasks + apps_profile_install_tasks($install_state, array('machine name' => 'panopoly', 'default apps' => array('panopoly_demo')));

  // Add the Panopoly theme selection to the installation process
  // require_once(drupal_get_path('module', 'panopoly_theme') . '/panopoly_theme.profile.inc');
  // $tasks = $tasks + panopoly_theme_profile_theme_selection_install_task($install_state);

  return $tasks;
}

/**
 * Implements hook_install_tasks_alter()
 */
function adapted_install_tasks_alter(&$tasks, $install_state) {

  // Magically go one level deeper in solving years of dependency problems
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  $tasks['install_load_profile']['function'] = 'panopoly_core_install_load_profile';

  // Since we only offer one language, define a callback to set this
  require_once(drupal_get_path('module', 'panopoly_core') . '/panopoly_core.profile.inc');
  $tasks['install_select_locale']['function'] = 'panopoly_core_install_locale_selection';

  // Custom install_finished callback
  //$tasks['install_finished']['function'] = 'adapted_install_finished';

  // Set the install theme to adaptive theme core
  _adapted_set_theme('sizzle');

}

/**
 * Implements hook_form_FORM_ID_alter()
 */
function adapted_form_install_configure_form_alter(&$form, $form_state) {

  // Hide some messages from various modules that are just too bitchy.
  drupal_get_messages('status');
  drupal_get_messages('warning');

  // Set reasonable defaults for site configuration form
  $form['site_information']['site_name']['#default_value'] = 'Adapted';
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['server_settings']['site_default_country']['#default_value'] = 'CA';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Vancouver'; // West coast, best coast

  // Define a default email address if we can guess a valid one
  if (valid_email_address('admin@' . $_SERVER['HTTP_HOST'])) {
    $form['site_information']['site_mail']['#default_value'] = 'admin@' . $_SERVER['HTTP_HOST'];
    $form['admin_account']['account']['mail']['#default_value'] = 'admin@' . $_SERVER['HTTP_HOST'];
  }
}

/**
 * Callback for install_finished task
 */
/*function adapted_install_finished(&$install_state) {

  require_once(drupal_get_path('profile', 'adapted') . '/files/includes/install.themes.inc');
  adapted_themes_build();

  require_once(drupal_get_path('profile', 'adapted') . '/files/includes/install.finished.inc');
  adapted_finished_build();

}*/

/**
 * Sets the installation theme for Adapted profile
 */
function _adapted_set_theme($theme) {
  if ($GLOBALS['theme'] != $theme) {
    unset($GLOBALS['theme']);

    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $theme;
    _drupal_maintenance_theme();
  }
}

<?php
/**
 * @file
 * adapted_themes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function adapted_themes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}


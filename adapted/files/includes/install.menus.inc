<?php

function adapted_menus_build() {

  // Set the menus
  variable_set('menu_main_links_source', 'main-menu');
  variable_set('menu_secondary_links_source', 'main-menu');

  // Create a Home link in the main menu.
  $item = array(
    'link_title' => st('Home'),
    'link_path' => '<front>',
    'menu_name' => 'main-menu',
    'weight' => -50,
  );
  menu_link_save($item);
  
  // Update the menu router information.
  menu_rebuild();
  
}

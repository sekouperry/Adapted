<?php

function adapted_performance_settings() {

  variable_set('cache', '1');
  variable_set('block_cache', '1');
  variable_set('cache_lifetime', '60');
  variable_set('page_compression', '1');
  variable_set('preprocess_css', '1');
  variable_set('preprocess_js', '1');

}

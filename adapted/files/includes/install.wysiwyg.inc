<?php
  //  Sets default WYSIWYG settings for Adapted (Thanks OpenPublish!)
  function adapted_set_wysiwyg_settings() {
  $settings = array(
    'default' => 1,
    'user_choose' => 1,
    'show_toggle' => 1,
    'theme' => 'advanced',
    'language' => 'en',
    'buttons' => array(
      'default' => array(
        'Bold' => 1,
        'Italic' => 1,
        'Underline' => 1,
        'Strike' => 1,
        'JustifyLeft' => 1,
        'JustifyCenter' => 1,
        'JustifyRight' => 1,
        'BulletedList' => 1,
        'NumberedList' => 1,
        'Undo' => 1,
        'Redo' => 1,
        'Link' => 1,
        'Unlink' => 1,
        'Anchor' => 1,
        'Image' => 1,
        'Superscript' => 1,
        'Subscript' => 1,
        'Blockquote' => 1,
        'HorizontalRule' => 1,
        'Cut' => 1,
        'Copy' => 1,
        'Paste' => 1,
        'PasteFromWord' => 1,
        'RemoveFormat' => 1,
        'SpecialChar' => 1,
        'Format' => 1,
        'Table' => 1,
        'Maximize' => 1,
      ),
      'imce' => array(
        'imce' => 1,
      ),
    ),
    'toolbar_loc' => 'top',
    'toolbar_align' => 'left',
    'path_loc' => 'bottom',
    'resizing' => 1,
    'verify_html' => 1,
    'preformatted' => 0,
    'convert_fonts_to_spans' => 1,
    'remove_linebreaks' => 1,
    'apply_source_formatting' => 0,
    'paste_auto_cleanup_on_paste' => 1,
    'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
    'css_setting' => 'self',
    'css_path' => '%t/css/editor.css',
    'css_classes' => '',
  );

  $fields = array(
    'format' => 'full_html',
    'editor' => 'ckeditor',
    'settings' => serialize($settings),
  );

  db_insert('wysiwyg')->fields($fields)->execute();

  db_update('filter_format')
  ->condition('format', 'filtered_html')
  ->fields(array('weight' => 1))
  ->execute();

  db_update('filter_format')
  ->condition('format', 'full_html')
  ->fields(array('weight' => 0))
  ->execute();
}

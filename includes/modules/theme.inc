<?php

function twitter_bootstrap_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $output = '';

  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      $data = '';
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 0) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items - 1) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
 
  return $output;
}

function twitter_bootstrap_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'), 
    'error' => t('Error message'), 
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    if (count($messages) > 1) {
      foreach ($messages as $message) {
        $output .= "<div class=\"alert-message $type\" data-alert=\"data-alert\">\n";
        $output .= "  <a class=\"close\" href=\"#\">x</a>\n";
        $output .= '  <p>' . $message . "</p>\n";
        $output .= " </div>\n";
      }  
    }
    else {
      $output .= $messages[0];
    }
  }
  return $output;
}

function twitter_bootstrap_css_alter(&$css) {
  $excludes = _twitter_bootstrap_alter(twitter_bootstrap_theme_get_info('exclude'), 'css');
  $css = array_diff_key($css, $excludes);
}
 
function twitter_bootstrap_js_alter(&$js) {
  $excludes = _twitter_bootstrap_alter(twitter_bootstrap_theme_get_info('exclude'), 'js');
  $js = array_diff_key($js, $excludes);
}

function _twitter_bootstrap_alter($files, $type) {
  $output = array();
  foreach($files as $key => $value) {
	  foreach($files[$key][$type] as $file => $name) {
		  $output[$name] = FALSE;
	  }
  }
  return $output;
}
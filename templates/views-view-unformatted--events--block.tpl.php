<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title: The title of this group of rows.  May be empty.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are indexed by row number.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<ul class="list-group list-group-lg">
  <?php foreach ($rows as $row_count => $row): ?>
    <li class="list-group-item">
<div class="row">
        <?php print $row; ?>
        </div>
    </li>
  <?php endforeach; ?>
</ul>

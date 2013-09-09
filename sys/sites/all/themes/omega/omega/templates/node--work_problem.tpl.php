<article<?php print $attributes; ?>>
  <?php print $user_picture; ?>
  <?php print render($title_prefix); ?>
  <?php if (!$page && $title): ?>
  <header>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  </header>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
  <?php if ($display_submitted): ?>
  <footer class="submitted"><?php print $date; ?> -- <?php print $name; ?></footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
    <div>
      <div class="sub-title-2">3.1 สิ่งที่เป็นอุปสรรคต่อการทำงาน</div>
      <?php echo $node->body['und'][0]['value']; ?>
    </div>
    <div>
      <br />
      <div class="sub-title-2">3.2 วิธีการแก้ไข และข้อเสนอแนะ</div>
      <?php echo $node->field_work_problem_resole['und'][0]['value']; ?>
    </div>
    <div class="routine-assessment-footer">
      <?php print l("แก้ไขสิ่งที่เป็นอุปสรรค์ต่อการทำงาน", "node/".$node->nid."/edit", array("query"=>array("destination"=>"portfolio/me/work-problem"))) ?>
    </div>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>

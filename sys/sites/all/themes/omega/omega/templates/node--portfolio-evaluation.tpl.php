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
    <div class="estimate-content">
        <div class="lable">งานอะไรบ้างที่เป็นปัญหา และอุปสรรคต่อการทำงาน รวมถึงท่านคิดว่าจะมีวิธีการแก้ไขปัญหาที่พบได้อย่างไร</div>
        <?php print views_embed_view('estimate_problem_content', 'default', $node->nid); ?>
    </div>

    <div class="estimate-content">
        <div class="lable">งานที่มีผลการดำเนินการที่ภาคภูมิใจตลอดปีงบประมาณที่ผ่านมา</div>
        <?php print views_embed_view('estimate_pround_content', 'default', $node->nid); ?>
    </div>

    <div class="estimate-content">
        <div class="lable">งานที่คิดว่าเป็นงานที่มีคุณค่าเกิดประโยชน์ต่อมหาวิทยาลัยและสังคม</div>
        <?php print views_embed_view('estimate_best_content', 'default', $node->nid); ?>
    </div>
  </div>

  <?php print portfolio_menu_footer($node->field_profile_ref['und'][0]['nid'], 'portfolio-evaluation', $node->nid) ?>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>
</article>

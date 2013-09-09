<?php
    /*debug english name*/
    if (!isset($node->field_name_en['und'])) {
        $name_en = '<div class="english-name">'.t("English Name").'</div>';
    }
    else {
        $name_en = strip_tags(drupal_render($content['field_name_en']))." ".strip_tags(drupal_render($content['field_lastname_en']));
    }

    /*check work postion*/
    $work_position = (isset($node->field_work_position['und'])) ? taxonomy_term_load($node->field_work_position['und']['0']['tid'])->name : "-" ;

    /*check email*/
    $mail = (isset($node->field_person_email['und'])) ? drupal_render($content['field_person_email']) : '<span class="field-label">อีเมล์: </span>info@sskru.ac.th' ;

    /*reformat faculty*/
    $fac_tmp = explode("›", strip_tags(drupal_render($content['field_faculty'])));
    if (count($fac_tmp) == 2) {
        $faculty = '<span class="field-label">สังกัดหน่วยงาน: </span>'.$fac_tmp[1];
    }else {
        $tmp = explode(":", $fac_tmp[0]);
        $faculty = '<span class="field-label">สังกัดหน่วยงาน: </span>'.$tmp[1];
    }

    /*check education profile*/
    if (!$teaser) {
        $ed_check = 0;
        $ed_check = db_select('field_data_field_profile_ref', 'p')
                    ->fields('p', array('entity_id'))
                    ->condition('bundle', 'educational_background', '=')
                    ->condition('field_profile_ref_nid', $node->nid, '=')
                    ->range(0, 1)
                    ->execute()
                    ->fetchColumn();
     }

?>

<?php if ($teaser): ?>
    <div class="person-profile teaser">
        <div class="grid-3 prfile-photo">
            <?php print drupal_render($content['field_person_image']) ?>
        </div>
        <div class="grid-5 prfile-content">
            <div class="name-th"><?php print l($title, "node/".$node->nid) ?></div>
            <div class="name-en">
                <?php print $name_en; ?>
            </div>
            <div class="work-position">
                <span class="field-label">ตำแหน่งงาน: </span>
                <?php print $work_position; ?>
            </div>
            <div class="phone">
                <?php print drupal_render($content['field_person_phone']) ?>
            </div>
            <div class="mail">
                <?php print $mail ?>
            </div>
            <div class="faculty">
                <?php print $faculty ?>
            </div>
        </div>
        <div class="clearfix"></div>
    </div>
<?php else: ?>
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

            <!-- Display Content -->
            <div class="person-profile">
                <div class="grid-3 prfile-photo">
                    <?php print drupal_render($content['field_person_image']) ?>
                </div>
                <div class="grid-5 prfile-content">
                    <div class="name-th"><?php print l($title, "node/".$node->nid) ?></div>
                    <div class="name-en">
                        <?php print $name_en; ?>
                    </div>
                    <div class="work-position">
                        <span class="field-label">ตำแหน่งงาน: </span>
                        <?php print $work_position; ?>
                    </div>
                    <div class="phone">
                        <?php print drupal_render($content['field_person_phone']) ?>
                    </div>
                    <div class="mail">
                        <?php print $mail ?>
                    </div>
                    <div class="faculty">
                        <?php print $faculty ?>
                    </div>
                </div>
                <div class="clearfix"></div>

                <div class="profile-detail">
                    <!-- Education Background -->
                    <?php if ($ed_check): ?>
                        <div class="sub-title">ประวัติการศึกษา</div>
                        <?php print views_embed_view('degree_ref_content_list', 'default', $node->nid) ?>
                    <?php endif ?>
                </div>

            </div>
        </div>
        <div class="clearfix">
            <?php if (!empty($content['links'])): ?>
                <nav class="links node-links clearfix"><?php print render($content['links']); ?></nav>
            <?php endif; ?>
            <?php print render($content['comments']); ?>
        </div>
    </article>
<?php endif ?>

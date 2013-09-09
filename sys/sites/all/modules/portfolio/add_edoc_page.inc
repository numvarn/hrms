<?php
function portfolio_add_edoc_page() {
    global $user;
    $output = '';

    $profile_nid  = '';
    $profile_nid .= profile_manager_get_profile_nid($user->uid);

    $output .= '
        <div class="profile-edoc-list">
            '.views_embed_view('profile_edocument_display', 'default', $profile_nid).'
        </div>
        <div class="edoc-selecter">
            '.views_embed_view('edocument_selecter', 'default').'
        </div>
    ';

    return $output;
}

function portfolio_edoc_delete($edoc_ref) {
    node_delete($edoc_ref->nid);
    drupal_goto('portfolio/me/edoc-add');
}

function portfolio_edoc_add($edoc) {
    global $user;
    $profile_nid = 0;
    $profile_nid .= profile_manager_get_profile_nid($user->uid);

    $output = '';
    $check_nid = 0;

    $query = db_select('field_data_field_profile_ref', 'p');
    $query->join('field_data_field_edocument_ref', 'e', 'p.entity_id=e.entity_id');
    $result = $query
                ->fields('p', array('entity_id'))
                ->condition('p.field_profile_ref_nid', $profile_nid, '=')
                ->condition('e.field_edocument_ref_nid', $edoc->nid, '=')
                ->execute();

    $check_nid = $result->fetchColumn();

    if ($check_nid == 0) {
        $node = new stdClass();
        $node->type  = 'profile_edocument';
        $node->title = 'profile edocument';

        $node->language   = LANGUAGE_NONE;
        $node->uid        = $user->uid;
        $node->created    = time();
        $node->changed    = $node->created;
        $node->status     = 1;
        $node->promote    = 0;
        $node->sticky     = 0;
        $node->format     = 0;
        $node->revision   = 1;
        $node->log        = t('Node saved: '.$node->title);

        if (isset($edoc->field_edoc_from['und'])) {
            $node->field_edoc_from['und'][0]['tid'] = $edoc->field_edoc_from['und'][0]['tid'];
        }

        $node->field_profile_ref['und'][0]['nid'] = $profile_nid;
        $node->field_edocument_ref['und'][0]['nid'] = $edoc->nid;
        $node->field_edoc_type['und'][0]['tid'] = $edoc->field_edoc_type['und'][0]['tid'];
        $node->field_edoc_date['und'][0]['value'] = $edoc->field_edoc_date['und'][0]['value'];
        $node->field_edoc_code['und'][0]['value'] = $edoc->field_edoc_code['und'][0]['value'];
        $node->field_edoc_title['und'][0]['value'] = $edoc->field_edoc_title['und'][0]['value'];

        node_save($node);

        drupal_set_message('เพิ่มรายชื่อหนังสือเข้าไปในรายการแล้ว');
    }
    else {
        drupal_set_message('หนังสือนี้มีอยู่แล้วในรายการ');
    }

    drupal_goto('portfolio/me/edoc-add');
}

<?php

// portfolio_addons_assessment_new
/**
 * Portfolio Display Page
 */
function portfolio_page($profile_nid=NULL) {
    $output = '';

    //Add Smooth Scroll JS
    drupal_add_js(drupal_get_path('module', 'portfolio')."/scroll.js");

    // get profile nid
    if ($profile_nid == NULL) {
        $profile_nid = portfolio_get_profile_nid();
    }

    /**
     * Output Education Profile
     */
    $output_ed_profile = '';
    if (portfolio_check_content('educational_background', $profile_nid)) {
        $output_ed_profile .= '
            <div class="portfolio-me-sec-2">
                <div class="sub-title">ประวัติการศึกษา</div>
                '.views_embed_view('degree_ref_content_list', 'default', $profile_nid).'
            </div>';
    }

    /**
     * Output Working Profile
     */
    $output_working_profile = '';
    if (portfolio_check_content('personnal_working_profile', $profile_nid)) {
        $output_working_profile = '
            <div id="working-profile"></div>
            <div class="working-profile">
                <div class="sub-title">ประวัติการทำงานภายนอกสถาบัน</div>
                '.views_embed_view('working_profile_content', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'personnal-working-profile').'
            </div>';
    }

    /**
     * Output Insignia
     */
    $output_insignia = "";
    if (portfolio_check_content('insignia', $profile_nid)) {
        $output_insignia = '
            <div class="insignia-profile">
                <div class="sub-title">ประวัติการได้รับเครื่องราชอิสริยาภรณ์</div>
                '.views_embed_view('insignia_profile_list', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Academic Position Profile
     */
    $output_academic_position = '';
    if (portfolio_check_content('academic_position_profile', $profile_nid)) {
        $output_academic_position = '
            <div class="academic-position-profile">
                <div class="sub-title">การดำรงตำแหน่งทางวิชาการ / สูงขึ้น</div>
                '.views_embed_view('academic_position_profile', 'default', $profile_nid).'
            </div>
        ';
    }else {
        $output_academic_position = portfolio_academic_postion_empty();
    }

    /**
     * Output Inner SSKRU Working Profile
     */
    $output_academic_position_inner = '';
    if (portfolio_check_content('personnal_working_profile_inner', $profile_nid)) {
        $output_academic_position_inner = '
            <div id="working-inner-profile"></div>
            <div class="academic-position-profile">
                <div class="sub-title">ประวัติการทำงานภายในสถาบัน</div>
                '.views_embed_view('clone_of_working_profile_inner_content', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'personnal-working-profile-inner').'
            </div>
        ';
    }

    /**
     * Output Seminar Profile Inner SSKRU
     */
    $output_seminar_inner = '';
    if (portfolio_check_content('seminar_profile_inner', $profile_nid)) {
        $output_seminar_inner = '
            <div id="seminar-inner-profile"></div>
            <div class="seminar-inner-profile">
                <div class="sub-title">ประชุม/อบรม/สัมนาภายในสถาบัน</div>
                '.views_embed_view('seminar_profile_inner_content', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'seminar-profile-inner').'
            </div>
        ';
    }

    /**
     * Output Seminar Profile Outter SSKRU
     */
    $output_seminar_outter = '';
    if (portfolio_check_content('seminar_profile_outter', $profile_nid)) {
        $output_seminar_outter = '
            <div id="seminar-outter-profile">
            <div class="seminar-inner-profile">
                <div class="sub-title">ประชุม/อบรม/สัมนาภายนอกสถาบัน</div>
                '.views_embed_view('seminar_profile_outter_content', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'seminar-profile-outter').'
            </div>
        ';
    }

    /**
     * Output Award Profile
     */
    $output_award_profile = '';
    if (portfolio_check_content('award_profile', $profile_nid)) {
        $output_award_profile = '
            <div id="award-profile">
            <div class="award-profile">
                <div class="sub-title">ประวัติการได้รับรางวัล</div>
                '.views_embed_view('award_profile_content', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'award-profile').'
            </div>
        ';
    }

    /**
     * Output Analysis Self
     */
    $output_analysis_self = '';
    if (portfolio_check_content('analysis_self', $profile_nid)) {
        $output_analysis_self = '
            <div id="analysis-self"></div>
            <div class="analysis-self-me">
                <div class="sub-title">ประเมินตนเอง</div>
                '.views_embed_view('analysis_self_dispaly', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Analysis Self to Work
     */
    $output_analysis_self_to_work = '';
    if (portfolio_check_content('analysis_self_to_work', $profile_nid)) {
        $output_analysis_self_to_work = '
            <div id="analysis-self-to-work"></div>
            <div class="analysis-self-me">
                <div class="sub-title">การวิเคราะห์ความเป็นไปได้ในประโยชน์ของงานต่อตนเอง</div>
                '.views_embed_view('analysis_self_to_work_dispaly', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Analysis Self to University
     */
    $output_analysis_self_to_university = '';
    if (portfolio_check_content('analysis_self_to_university', $profile_nid)) {
        $output_analysis_self_to_university = '
            <div id="analysis-self-to-university"></div>
            <div class="analysis-self-me">
                <div class="sub-title">การวิเคราะห์ความเป็นไปได้ในประโยชน์ของงานต่อมหาวิทยาลัย</div>
                '.views_embed_view('analysis_self_to_university_dispaly', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Requirement to Education
     */
    $output_requirement_to_education = '';
    if (portfolio_check_content('requirement_in_education', $profile_nid)) {
        $output_requirement_to_education = '
            <div id="requirement-to-education"></div>
            <div class="requirement-to-education">
                <div class="sub-title">การวิเคราะห์ความต้องการการพัฒนาด้านวิชาการ</div>
                '.views_embed_view('requirement_in_ed_page', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Requirement to Work
     */
    $output_requirement_to_work = '';
    if (portfolio_check_content('requirement_in_work', $profile_nid)) {
        $output_requirement_to_work = '
            <div id="requirement-to-work"></div>
            <div class="requirement-to-work">
                <div class="sub-title">การวิเคราะห์ความต้องการการพัฒนาด้านหน้าที่การงาน</div>
                '.views_embed_view('requirement_in_work_page', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Estimate
     */
    $output_estimate = '';
    if (portfolio_check_content('portfolio_evaluation', $profile_nid)) {
        $output_estimate = '
            <div id="portfolio-evaluation"></div>
            <div class="portfolio-evaluation">
                <div class="sub-title">การประเมินผล</div>
                '.views_embed_view('estimate_content', 'default', $profile_nid).'
            </div>
        ';
    }

    /**
     * Output Profile Teaching
     */
    $output_profile_teaching = '';
    if (portfolio_check_content('profile_teaching', $profile_nid)) {
        $output_profile_teaching = '
            <div id="portfolio-teaching"></div>
            <div class="portfolio-teaching">
                <div class="sub-title">งานสอน</div>
                '.views_embed_view('profile_teaching_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-teaching').'
            </div>
        ';
    }

    /**
     * Output Profile Recipe
     */
    $output_recipe = '';
    if (portfolio_check_content('profile_recipe', $profile_nid)) {
        $output_recipe = '
            <div id="portfolio-recipe"></div>
            <div class="portfolio-recipe">
                <div class="sub-title">การผลิตเอกสารประกอบการสอน / ตำรา / สื่อการสอน</div>
                '.views_embed_view('profile_recipe_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-recipe').'
            </div>
        ';
    }

    /**
     * Output Profile Research
     */
    $output_research = '';
    if (portfolio_check_content('research', $profile_nid)) {
        $output_research = '
            <div id="profile-research"></div>
            <div class="profile-research">
                <div class="sub-title">งานวิจัย/งานสร้างสรรค์</div>
                '.views_embed_view('profile_research_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'research').'
            </div>
        ';
    }

    /**
     * Output Profile Publication
     */
    $output_publication = '';
    if (portfolio_check_content('publication', $profile_nid)) {
        $output_publication = '
            <div id="profile-publication"></div>
            <div class="profile-publication">
                <div class="sub-title">เอกสารตีพิมพ์</div>
                '.views_embed_view('profile_publication_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'publication').'
            </div>
        ';
    }

    /**
     * Output Profile Publication
     */
    $output_conference = '';
    if (portfolio_check_content('conference', $profile_nid)) {
        $output_conference = '
            <div id="profile-conference"></div>
            <div class="profile-conference">
                <div class="sub-title">การนำเสนอในงานประชุมวิชาการ</div>
                '.views_embed_view('profile_conference_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'conference').'
            </div>
        ';
    }

    /**
     * Output Profile Publication
     */
    $output_article = '';
    if (portfolio_check_content('profile_article', $profile_nid)) {
        $output_article = '
            <div id="profile-article"></div>
            <div class="profile-article">
                <div class="sub-title">การเผยแพร่งานเขียนเชิงวิชาการ</div>
                '.views_embed_view('profile_article_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-article').'
            </div>
        ';
    }

    /**
     * Output Student Union
     */
    $output_student = '';
    if (portfolio_check_content('profile_student_union', $profile_nid)) {
        $output_student = '
            <div id="profile-student"></div>
            <div class="profile-student">
                <div class="sub-title">งานกิจกรรมนักศึกษา (ที่ปรึกษาชมรม / การร่วมกิจกรรมนักศึกษา)</div>
                '.views_embed_view('student_union_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-student-union').'
            </div>
        ';
    }

    /**
     * Output Culture
     */
    $output_culture = '';
    if (portfolio_check_content('profile_culture', $profile_nid)) {
        $output_culture = '
            <div id="profile-culture"></div>
            <div class="profile-culture">
                <div class="sub-title">การทำนุบำรุงศิลปะและวัฒนธรรม</div>
                '.views_embed_view('profile_culture_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-culture').'
            </div>
        ';
    }

     /**
     * Output Lecture Inner
     */
    $output_lecturer = '';
    if (portfolio_check_content('profile_lecturer_inner', $profile_nid)) {
        $output_lecturer = '
            <div id="profile-lecturer"></div>
            <div class="profile-lecturer">
                <div class="sub-title">การเป็นวิทยากรภายในสถาบัน</div>
                '.views_embed_view('profile_lecturer_inner', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-lecturer-inner').'
            </div>
        ';
    }

    /**
     * Output Lecture Outter
     */
    $output_lecturer_outter = '';
    if (portfolio_check_content('profile_lecturer_outter', $profile_nid)) {
        $output_lecturer_outter = '
            <div id="profile-lecturer-outter"></div>
            <div class="profile-lecturer">
                <div class="sub-title">การเป็นวิทยากรภายนอกสถาบัน</div>
                '.views_embed_view('profile_lecturer_outter', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-lecturer-outter').'
            </div>
        ';
    }


    /**
     * Output ED Services
     */
    $output_ed_services = '';
    if (portfolio_check_content('profile_ed_services', $profile_nid)) {
        $output_ed_services = '
            <div id="profile-serivces"></div>
            <div class="profile-serivces">
                <div class="sub-title">การมีส่วนร่วมในการบริการวิชาการแก่สังคม</div>
                '.views_embed_view('profile_ed_services_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-ed-services').'
            </div>
        ';
    }

    /**
     * Output Thesis Consult
     */
    $output_thesis = '';
    if (portfolio_check_content('profile_thesis_consult', $profile_nid)) {
        $output_thesis = '
            <div id="profile-thesis"></div>
            <div class="profile-thesis">
                <div class="sub-title">การเป็นที่ปรึกษาวิทยานิพนธ์</div>
                '.views_embed_view('profile_thesis_consult', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-thesis-consult').'
            </div>
        ';
    }

    /**
     * Output Education Committee
     */
    $output_education_committee = '';
    if (portfolio_check_content('education_committee', $profile_nid)) {
        $output_education_committee = '
            <div id="education-committee"></div>
            <div class="profile-profession-committee">
                <div class="sub-title">การเป็นกรรมการวิชาการภายนอกสถาบัน</div>
                '.views_embed_view('education_committee_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'education-committee').'
            </div>
        ';
    }

    /**
     * Output Profession Committee
     */
    $output_profession_committee = '';
    if (portfolio_check_content('profile_profession_committee', $profile_nid)) {
        $output_profession_committee = '
            <div id="profile-profession-committee"></div>
            <div class="profile-profession-committee">
                <div class="sub-title">การเป็นกรรมการวิชาชีพภายนอกสถาบัน</div>
                '.views_embed_view('profession_committee_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-profession-committee').'
            </div>
        ';
    }

    /**
     * Output Profile Edocument
     */
    $output_profile_edoc = '';
    if (portfolio_check_content('profile_edocument', $profile_nid)) {
        $output_profile_edoc = '
            <div id="profile-edocument"></div>
            <div class="profile-edoc-list">
                <div class="sub-title">ภาระงานอื่นๆ</div>
                '.views_embed_view('profile_edocument_display', 'default', $profile_nid).'
                '.portfolio_menu_footer($profile_nid, 'profile-edocument').'
            </div>
        ';
    }

    /**
     * Display Template
     */
    $output .= '
        <div id="top"></div>
        <div class="portfolio-me-sec-1">
            <div class="grid-8">
                '.drupal_render(node_view(node_load($profile_nid), $view_mode='teaser')).'
                '.profile_manager_display_personal_data($profile_nid).'
                '.$output_ed_profile.'
                '.$output_academic_position.'
            </div>
            <div class="grid-4">
                '.portfolio_menu_list($profile_nid).'
            </div>
            <div class="clearfix"></div>
            '.$output_insignia.'
            '.$output_working_profile.'
            '.$output_academic_position_inner.'
            '.$output_seminar_inner.'
            '.$output_seminar_outter.'
            '.$output_award_profile.'

            '.$output_profile_teaching.'
            '.$output_recipe.'
            '.$output_research.'
            '.$output_publication.'
            '.$output_conference.'
            '.$output_article.'
            '.$output_student.'
            '.$output_culture.'
            '.$output_ed_services.'
            '.$output_lecturer.'
            '.$output_lecturer_outter.'
            '.$output_thesis.'
            '.$output_education_committee.'
            '.$output_profession_committee.'
            '.$output_profile_edoc.'

        <!-- #Comment By Phisan Sookkhee On 08-07-2013
            '.$output_analysis_self.'
            '.$output_analysis_self_to_work.'
            '.$output_analysis_self_to_university.'

            '.$output_requirement_to_education.'
            '.$output_requirement_to_work.'
            '.$output_estimate.'
        -->
        </div>';

    /*Debug set page title agin*/
    drupal_set_title(t('แฟ้มสะสมผลงานออนไลน์'));

    return $output;
}

?>

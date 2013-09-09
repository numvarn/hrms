<?php
function excel_report_person() {
    require 'code.php';

    $output = '';
    $file_path = '/Users/numvarn/Desktop/file.csv';
    $fp = fopen($file_path, "w");

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_birthday', 'dob', 'dob.entity_id=n.nid');
    $result = $query
                ->fields('n', array('nid'))
                ->condition('n.type', 'personal_profile', '=')
                ->orderby('dob.field_birthday_value', 'ASC')
                ->execute();

    /*Write Header */
    $arr = array(
            0 => 'YEAR',
            1 => 'UNIV_ID',
            2 => 'CITIZEN_ID',
            3 => 'PREFIX_NAME',
            4 => 'STF_FNAME',
            5 => 'STF_LNAME',
            6 => 'GENDER_ID',
            7 => 'BIRTHDAY',
            8 => 'HOMEADD',
            9 => 'MOO',
            10 => 'STREET',
            11 => 'DISTRICT',
            12 => 'AMPHUR',
            13 => 'PROVINCE_ID',
            14 => 'TELEPHONE',
            15 => 'ZIPCODE',
            16 => 'NATION_ID',
            17 => 'STAFFTYPE_ID',
            18 => 'TIME_CONTACT_ID',
            19 => 'BUDGET_ID',
            20 => 'SUBSTAFFTYPE_ID',
            21 => 'ADMIN_POSITION_ID',
            22 => 'POSITION_ID',
            23 => 'POSITION_WORK',
            24 => 'DEPARTMENT_ID',
            25 => 'DATE_INWORK',
            26 => 'STAFF_LEV_ID',
            27 => 'SPECIAL_NAME',
            28 => 'TEACH_ISCED_ID',
            29 => 'GRAD_LEV_ID',
            30 => 'GRAD_CURR',
            31 => 'GRAD_ISCED_ID',
            32 => 'GRAD_PROG_ID',
            33 => 'GRAD_UNIV',
            34 => 'GRAD_COUNTRY_ID',
        );
    fputcsv($fp, $arr);
    unset($arr);

    while ($nid = $result->fetchColumn()) {
        $person = node_load($nid);

        // Check DOB
        $dob = '';
        if ($person->field_birthday['und'][0]['value'] != '') {
            $year = format_date($person->field_birthday['und'][0]['value'], 'custom', 'Y') + 543;
            $dob = format_date($person->field_birthday['und'][0]['value'], 'custom', 'd/m')."/".$year;
        }

        // Check Address
        $address = '';
        if (isset($person->field_home_address['und'])) {
            $address = $person->field_home_address['und'][0]['value'];
        }

        $moo = '';
        if (isset($person->field_home_address_moo['und'])) {
            $moo = $person->field_home_address_moo['und'][0]['value'];
        }

        $street = '';
        if (isset($person->field_home_address_road['und'])) {
            $street = $person->field_home_address_road['und'][0]['value'];
        }

        $zipcode = '';
        if (isset($person->field_home_address_zipcode['und'])) {
            $zipcode = taxonomy_term_load($person->field_home_address_zipcode['und'][0]['tid'])->name;
        }

        // Check Phone
        $phone = '';
        if (isset($person->field_person_phone['und'])) {
            $phone = $person->field_person_phone['und'][0]['value'];
        }

        // Get province ID
        $province_id = '';
        if (isset($person->field_home_address_province['und'])) {
            $province_name = taxonomy_term_load($person->field_home_address_province['und'][0]['tid'])->name;
            $province_id = array_search($province_name, $ref_province_name);
        }

        // Check staff type
        $staff_type_tid = $person->field_officer_type['und'][0]['tid'];
        if ($staff_type_tid == 18) {
            $staff_type_id = 1; //$ref_stafftype[1];
        }
        else if ($staff_type_tid == 55) {
            $staff_type_id = 2; //$ref_stafftype[2];
        }
        else if ($staff_type_tid == 72) {
            $staff_type_id = 3; //$ref_stafftype[3];
        }
        else if ($staff_type_tid == 50) {
            $staff_type_id = 4; //$ref_stafftype[4];
        }
        else if ($staff_type_tid == 414) {
            $staff_type_id = 5; //$ref_stafftype[5];
        }

        // Name Prefix ID
        $name_prefix = taxonomy_term_load($person->field_name_prefix['und'][0]['tid'])->name;
        $name_prefix_id = '';
        $name_prefix_id = array_search($name_prefix, $ref_prefix_name);

        // Check Gender
        //ref_gender
        $gender_name = taxonomy_term_load($person->field_gender['und'][0]['tid'])->name;
        $gender_id = '';
        $gender_id = array_search($gender_name, $ref_gender);

        // Get Department id
       if (isset($person->field_faculty['und'])) {
            $department = taxonomy_term_load($person->field_faculty['und'][0]['tid'])->name;
       }
       else {
            $department = 'สำนักงานอธิการบดี';
       }
       $department_id = array_search($department, $ref_fac);

       // Get WorkPostion
       $work_position = taxonomy_term_load($person->field_work_position['und']['0']['tid'])->name;

       // Get Postion ID
       $position_id = '';
       $ed_postion = '';
       if (isset($person->field_education_position['und'])) {
            $ed_postion = taxonomy_term_load($person->field_education_position['und']['0']['tid'])->name;
       }

       // double check
       if ($work_position == "อาจารย์" && $ed_postion == '') {
           $ed_postion = 'อาจารย์';
       }

       if ($ed_postion == '') {
           $ed_postion = 'ไม่มีตำแหน่งทางวิชาการ';
       }

       $position_id = array_search($ed_postion, $ref_position);

       // Get Date In Work
       $date_in_work = '';
       if (isset($person->field_start_working_date_first['und'])) {
            $year = format_date($person->field_start_working_date_first['und'][0]['value'], 'custom', 'Y') + 543;
            $date_in_work = format_date($person->field_start_working_date_first['und'][0]['value'], 'custom', 'd/m')."/".$year;
       }

       // Get Top Education Level
       $top_ed_level_code = '';
       if (isset($person->field_education_level['und'])) {
           $top_ed_level_tid = $person->field_education_level['und'][0]['tid'];
           if ($top_ed_level_tid == 486) {
               $top_ed_level_code = '03'; //ประถมศึกษา
           }
           else if ($top_ed_level_tid == 487 || $top_ed_level_tid == 488) {
               $top_ed_level_code = '10'; //มัธยมศึกษาตอนปลาย/ประกาศนียบัตรวิชาชีพ(ปวช.)
           }
           else if ($top_ed_level_tid == 489) {
               $top_ed_level_code = '05'; //มัธยมศึกษาตอนต้น/วุฒิที่ต่ำกว่าประกาศนียบัตรวิชาชีพ(ปวช.)
           }
           else if ($top_ed_level_tid == 6907 || $top_ed_level_tid == 6908) {
               $top_ed_level_code = '30'; //ประกาศนียบัตรวิชาชีพชั้นสูง
           }
           else if ($top_ed_level_tid == 12) {
               $top_ed_level_code = '40'; //ปริญญาตรี
           }
           else if ($top_ed_level_tid == 13) {
               $top_ed_level_code = '60'; //ปริญญาโท
           }
           else if ($top_ed_level_tid == 14) {
               $top_ed_level_code = '80'; //ปริญญาเอก
           }
       }

        $arr = array(
            0 => 2556,                                                          // 'YEAR',
            1 => 16300,                                                         // 'UNIV_ID'
            2 => $person->field_citizen_id['und'][0]['value'],                  // 'CITIZEN_ID'
            3 => $name_prefix_id,                                               // 'PREFIX_NAME'
            4 => $person->field_name_th['und'][0]['value'],                     // 'STF_FNAME'
            5 => $person->field_lastname_th['und'][0]['value'],                 // 'STF_LNAME'
            6 => $gender_id,                                                    // 'GENDER_ID'
            7 => $dob,                                                          // 'BIRTHDAY'
            8 => $address,                                                      // 'HOMEADD'
            9 => $moo,                                                          // 'MOO'
            10 => $street,                                                      // 'STREET'
            11 => '',                                                           // 'DISTRICT'
            12 => '',                                                           // 'AMPHUR'
            13 => $province_id,                                                 // 'PROVINCE_ID'
            14 => $phone,                                                       // 'TELEPHONE'
            15 => $zipcode,                                                     // 'ZIPCODE'
            16 => 'TH',                                                         // 'NATION_ID'
            17 => $staff_type_id,                                               // 'STAFFTYPE_ID'
            18 => '',                                                           // 'TIME_CONTACT_ID'
            19 => '',                                                           // 'BUDGET_ID'
            20 => '',                                                           // 'SUBSTAFFTYPE_ID'
            21 => '',                                                           // 'ADMIN_POSITION_ID'
            22 => $position_id,                                                  // 'POSITION_ID'
            23 => $work_position,                                               // 'POSITION_WORK'
            24 => $department_id,                                               // 'DEPARTMENT_ID'
            25 => $date_in_work,                                                // 'DATE_INWORK'
            26 => '',                                                           // 'STAFF_LEV_ID'
            27 => '',                                                           // 'SPECIAL_NAME'
            28 => '',                                                           // 'TEACH_ISCED_ID'
            29 => $top_ed_level_code,                                           // 'GRAD_LEV_ID'
            // 'GRAD_CURR'
            // 'GRAD_ISCED_ID'
            // 'GRAD_PROG_ID'
            // 'GRAD_UNIV'
            // 'GRAD_COUNTRY_ID'
        );

        fputcsv($fp, $arr);
        unset($arr);
    }
    // end while

    fclose($fp);

    $output .= "Already Export Data to CSV File";
    return $output;
}

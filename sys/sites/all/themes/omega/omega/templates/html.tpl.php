<?php print $doctype; ?>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf->version . $rdf->namespaces; ?>>
<head<?php print $rdf->profile; ?>>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- Phisan Edit style -->
  <?php if ($is_front): ?>
    <style type="text/css">
        /*#zone-content {
          background: url("sites/all/themes/omega/omega/images/first.jpg") no-repeat 0 0 transparent;
        }*/
        #zone-content-wrapper {
          background: url("sites/all/themes/omega/omega/images/zone-content-bg.png") repeat-x 0 0 transparent;
          background-position:center top;
        }
    </style>
  <?php endif ?>

  <!--[if lt IE 9]><script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script><![endif]-->
</head>
<body<?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>

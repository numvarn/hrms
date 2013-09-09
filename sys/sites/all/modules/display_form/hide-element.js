jQuery(document).ready(function() {
    jQuery('input:radio').change(function() {
        var value = jQuery("input[type='radio']:checked").val();
        if (value == 6279) {
            jQuery('.recipe-member').show('slow');
        };

        if (value == 6278) {
            jQuery('.recipe-member').hide('slow');
        };
    });
});

jQuery(document).ready(function() {
    var value = jQuery("input[type='radio']:checked").val();
    if (value == 6279) {
        jQuery('.recipe-member').show();
    };

    if (value == 6278) {
        jQuery('.recipe-member').hide();
    };
});

<?php

/**
 * @file
 * Implements admin functions for mopl
 */


/** Implements hook_mail()
 *  Defines the template for send mail
 */

function mopl_mail($key, &$message, $params) {
switch($key) {
case 'notice':
$langcode = $message['language']->language;
global $base_url;
$variables=array('!site'=>$base_url);
$message['subject'] = t('Complete payment at !site', $variables, array(
'langcode' => $langcode,
));
// If you wish replacements to make after translation, you may edit $variables below
$variables=array();
global $base_url;
$site_name=variable_get('site_name',$base_url);
$message['body'][] = t("Dear Customer,\n\nYou're ready to pay on this site.\n\nClick the below link.\n\n".$base_url."/start_transaction/".$params['hash_key']."\n\nBest Regards,\n".$site_name." Team",$variables, array('langcode' => $langcode,)
);
break;
}
}

/** Implements mopl_redirect_to_checkout()
 *  Set the appropriate session variable and redirect a
 *  customer to his/her checkout
 */
function mopl_redirect_to_checkout($checkout_hash){
dpm('redirect fn - '.$checkout_hash);
/* Fetch Order ID */
$order_id = db_query("SELECT order_id from {commerce_order} WHERE checkout_hash = :checkout_hash LIMIT 1", array(":checkout_hash" => $checkout_hash))->fetchField();
$_SESSION['commerce_cart_order_id']=$order_id;
$_SESSION['commerce_cart_orders'][] = $order_id;
drupal_session_start();
// Creating a checkout link
$checkout_link='checkout/'.$order_id;
// Redirecting the user to the checkout link created above
drupal_goto($checkout_link);
}


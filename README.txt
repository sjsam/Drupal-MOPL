mopl stands for Mail Order Payment Link

**Functionality**
To send a customer a payment link for an order which was incomplete or made by an admin (eg when the customer calls you and you create the order for them).

**Installation**
Follow the normal workflow for installing a module.

**Usage**
- Zero Configuration, but a mail transfer agent should be configured in the server.
- Automatically sends a checkout link to an anonymous user once an admin creates an
  order for him on the Drupal site using Drupal Commerce
- In the order, make sure the owner is set to anonymous, that is don't fill this field.
- Only anonymous users would be able to access the checkous - This is desired.
- If a logged in user tries to check out using the link received in the mail, he gets a  a Drupal 'page not found' warning. See the logs to confirm.



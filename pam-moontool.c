  /* Define which PAM interfaces we provide */
  #define PAM_SM_ACCOUNT

  /* Include PAM headers */
  #include <security/pam_appl.h>
  #include <security/pam_modules.h>

  /* PAM entry point for accounting */
  int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
          return(PAM_IGNORE);
  }

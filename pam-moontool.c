/* Define which PAM interfaces we provide */
#define PAM_SM_ACCOUNT

/* Include PAM headers */
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include <time.h>

#include "julian.h"
#include "moontool.h"

/* PAM entry point for accounting */
int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
	double cur_phase;

	time_t cur_time;
	time(&cur_time);
	struct tm* cur_gmt_time = gmtime(&cur_time);
	double cur_julian_time = jtime(cur_gmt_time);

	double phases[5];

	phasehunt(cur_julian_time, phases);
	double fullmoon_time = phases[2];
	if ((cur_julian_time - fullmoon_time) < 1) {
		return PAM_PERM_DENIED;
	}

	return PAM_IGNORE;
}

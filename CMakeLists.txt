project (pam-moontool)

add_library(pam_moontool SHARED moontool.c pam-moontool.c julian.c)
set_target_properties(pam_moontool PROPERTIES PREFIX "")
target_link_libraries(pam_moontool m)


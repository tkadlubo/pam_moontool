project (pam-moontool)

add_library(pam-moontool SHARED moontool.c pam-moontool.c julian.c)
target_link_libraries(pam-moontool m)

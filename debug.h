#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 0 /* Set to 1 to enable debug messages */

/* debug.c */
int dinfo(const char *format, ...);
int derror(const char *format, ...);
int dwarn(const char *format, ...);
int dsuccess(const char *format, ...);

#endif /* DEBUG_H */
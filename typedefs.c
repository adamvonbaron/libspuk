#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

/* Package structure which is used with a socket */
typedef struct{
/* URL to EXACT location where tarball is. */
char const * const url;
/* Y-you know what... I don't know why I declared this. */
//char const * const filename;
/* Location of tarball on server (Parent directory) */
char const * const location;
/* Size of tarball in bytes */
float size;
/* Checksums to be safe */
char const * const MD5SUM;
char const * const SHA512SUM;
}package;

/* Interface between a package and the files it has/will installed */
typedef struct{
/* Package that we will be dealing with */
package * software;
/* Array of file paths that point to EACH file that the package has installed */
char (* files[][]);
/*  */
}profile;

/* wrapper around the standard socket which helps with the creation of a socket tailored to a package */
typedef struct{
/* Protocol family to use. For example, AF_INET, which is a bunch of protocols to use with IPv4 */
const int address_family;
/* The type of transmission between the two computers. For example, SOCK_STREAM for a reliable connection */
const int socket_type;
/* That one parameter in socket() that everyone sets to 0 */
const int protocol;
/* Package that we will be dealing with */
package * software;
/* And finally, the regular socket. This is a function pointer to a socket() call with it's parameters
  equal to the values in address_family, socket_type, and protocol*/
int (*sock_desc) (int address_family, int socket_type, int protocol);
}spuket;

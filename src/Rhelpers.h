/* Convenience macros for R programming
 *
 */

#ifndef RHELPERS_H
#define RHELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Some of these come from MASS, some from packages developed under
 * the Omega project, and some from RS-DBI itself.
 */

#include "Rversion.h"
#include "Rdefines.h"
#include "S.h"
#define Sint  int
#define C_S_CPY(p)    COPY_TO_USER_STRING(p)    /* cpy C string to R */

/* We simplify one- and two-level access to object and list
 * (mostly built on top of jmc's macros)
 *
 * NOTE: Recall that list element vectors should *not* be set 
 * directly, but only thru SET_ELEMENT (Green book, Appendix A), e.g.,
 *      LIST_POINTER(x)[i] = NEW_CHARACTER(100);    BAD!!
 *      LST_EL(x,i) = NEW_CHARACTER(100);           BAD!!
 *      SET_ELEMENT(x, i, NEW_CHARACTER(100));      Okay
 *
 * It's okay to directly set the i'th element of the j'th list element:
 *      LST_CHR_EL(x,i,j) = C_S_CPY(str);           Okay (but not in R-1.2.1)
 *
 * For R >= 1.2.0 define
 *      SET_LST_CHR_EL(x,i,j,val)
 */

/* x[i] */
#define LGL_EL(x,i) LOGICAL_POINTER((x))[(i)]
#define INT_EL(x,i) INTEGER_POINTER((x))[(i)]
#define SGL_EL(x,i) SINGLE_POINTER((x))[(i)]
#define FLT_EL(x,i) SGL_EL((x),(i))
#define NUM_EL(x,i) NUMERIC_POINTER((x))[(i)]
#define DBL_EL(x,i) NUM_EL((x),(i))
#define RAW_EL(x,i) RAW_POINTER((x))[(i)]
#define LST_EL(x,i) VECTOR_ELT((x),(i))
#define CHR_EL(x,i) CHAR(STRING_ELT((x),(i)))
#define SET_CHR_EL(x,i,val)  SET_STRING_ELT((x),(i), (val))

/* x[[i]][j] -- can be also assigned if x[[i]] is a numeric type */
#define LST_CHR_EL(x,i,j) CHR_EL(LST_EL((x),(i)), (j))
#define LST_LGL_EL(x,i,j) LGL_EL(LST_EL((x),(i)), (j))
#define LST_INT_EL(x,i,j) INT_EL(LST_EL((x),(i)), (j))
#define LST_SGL_EL(x,i,j) SGL_EL(LST_EL((x),(i)), (j))
#define LST_FLT_EL(x,i,j) LST_SGL_EL((x),(i),(j))
#define LST_NUM_EL(x,i,j) NUM_EL(LST_EL((x),(i)), (j))
#define LST_DBL_EL(x,i,j) LST_NUM_EL((x),(i),(j))
#define LST_RAW_EL(x,i,j) RAW_EL(LST_EL((x),(i)), (j))
#define LST_LST_EL(x,i,j) LST_EL(LST_EL((x),(i)), (j))

/* x[[i]][j] -- for the case when x[[i]] is a character type */
#define SET_LST_CHR_EL(x,i,j,val) SET_STRING_ELT(LST_EL(x,i), j, val)

/* end of RS-DBI macros */

#ifdef __cplusplus
}
#endif

#endif /* RHELPERS_H */

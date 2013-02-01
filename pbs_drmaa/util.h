/* $Id: util.h 65 2012-01-15 16:18:16Z mmamonski $ */
/*
 *  FedStage DRMAA for PBS Pro
 *  Copyright (C) 2006-2009  FedStage Systems
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PBS_DRMAA__UTIL_H
#define __PBS_DRMAA__UTIL_H

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

/*compatibility hack - ugly but help to keep binary compatibility :/ */
#define PBSOLDE_PROTOCOL 15031
#define PBSOLDE_EXPIRED 15020


void pbsdrmaa_exc_raise_pbs( const char *function );
int pbsdrmaa_map_pbs_errno( int _pbs_errno );

struct attrl;

void pbsdrmaa_free_attrl( struct attrl *list );
void pbsdrmaa_dump_attrl( const struct attrl *attribute_list, const char *prefix );

struct attrl *pbsdrmaa_add_attr( struct attrl *head, const char *name, const char *value);

/**
 * Writes temporary file.
 * @param content   Buffer with content to write.
 * @param len       Buffer's length.
 * @return Path to temporary file.
 */
char *
pbsdrmaa_write_tmpfile( const char *content, size_t len );


#endif /* __PBS_DRMAA__UTIL_H */


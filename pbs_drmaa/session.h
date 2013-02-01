/* $Id: session.h 52 2012-01-07 20:21:29Z mmamonski $ */
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

#ifndef __PBS_DRMAA__SESSION_H
#define __PBS_DRMAA__SESSION_H

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <drmaa_utils/session.h>

typedef struct pbsdrmaa_session_s pbsdrmaa_session_t;

fsd_drmaa_session_t *
pbsdrmaa_session_new( const char *contact );

struct pbsdrmaa_session_s {
	fsd_drmaa_session_t super;

	void (*super_destroy)( fsd_drmaa_session_t *self );

	void (*super_apply_configuration)(fsd_drmaa_session_t *self);

	/*
	 * Pointer to standard wait_thread drmaa_utils function
	 */
	void* (*super_wait_thread)( fsd_drmaa_session_t *self );

	/*
	 * PBS connection (or -1 if not connected).
	 * A descriptor of socket conencted to PBS server.
	 */
	int pbs_conn;

	/*
	 * PBS folder - used by wait_thread which reads log files
	 */
	char * pbs_home;

	/*
	 * Wait thread reading logs active
	 */
	bool wait_thread_log;

	/*
	 * List of attributes which will be used to query jobs.
	 */
	struct attrl *status_attrl;

	/*
	 * Log file initial size - used by wait_thread which reads log files TODO: check if it can be safely moved to log_reader
 	 */
	off_t log_file_initial_size;

	/*
	 * Time we checked log file initial size - used by wait_thread which reads log files TODO: check if it can be safely moved to log_reader
 	 */
	time_t log_file_initial_time;

	/*
	 * Maximal number of retires in pbs_connect. Default 3
	 */
	int max_retries_count;

	/*
	 * Wait thread sleep time (in seconds). Default 1s.
	 */
	int wait_thread_sleep_time;

	/*
	 * The prefix of the directory where the job exit status information is stored (default: %HOME/.pbs-drmaa/
	 */
	char *job_exit_status_file_prefix;
};

#endif /* __PBS_DRMAA__SESSION_H */


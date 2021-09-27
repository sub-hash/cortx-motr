/* -*- C -*- */
/*
 * Copyright (c) 2012-2020 Seagate Technology LLC and/or its Affiliates
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For any questions about this software or licensing,
 * please email opensource@seagate.com or cortx-questions@seagate.com.
 *
 */


#include "lib/finject.h"
#include "net/test/node_bulk.h"		/* m0_net_test_node_bulk_init */
#include "net/test/initfini.h"

/**
   @defgroup NetTestInitFiniInternals Initialization/finalization of net-test
   @ingroup NetTestInternals

   @see
   @ref net-test

   @{
 */

int m0_net_test_init(void)
{
	if (USE_LIBFAB) {
		m0_fi_enable("libfab_target_notify", "lf_dummy_msg_snd");
		m0_fi_enable("libfab_dummy_msg_rcv_chk", "lf_dummy_msg_rcv");
	}
	return m0_net_test_node_bulk_init();
}

void m0_net_test_fini(void)
{
	if (USE_LIBFAB) {
		m0_fi_disable("libfab_target_notify", "lf_dummy_msg_snd");
		m0_fi_disable("libfab_dummy_msg_rcv_chk", "lf_dummy_msg_rcv");
	}
	m0_net_test_node_bulk_fini();
}

/** @} end of NetTestInitFiniInternals group */

/*
 *  Local variables:
 *  c-indentation-style: "K&R"
 *  c-basic-offset: 8
 *  tab-width: 8
 *  fill-column: 79
 *  scroll-step: 1
 *  End:
 */

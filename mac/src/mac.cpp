#include <iostream>
#include "../../rrc/inc/rrc.h"
#include "../../rlc/inc/rlc.h"
#include "../inc/mac.h"
#include "../../phy/inc/physical.h"

void mac_layer_call(ccch_info rlc_pdu)
{
	ul_sch_type Ul_sch;

	/**ul_sch variable is created and passed to physical layer**/

	Ul_sch.mac_sdu=rlc_pdu;
	/**in below condition if rlc_pdu.ccch is ul_ccch then only mac layer will pas corresponding channel or else
	not**/

	if(rlc_pdu.ccch==ul_ccch)
	{
		printf("\nUL_ccch is passed to physical layer");

		/**here allocating UL_SCH what kind of channel is used by mac so PHYSICAL layer will use corresponding
		channels**/
		Ul_sch.sch=ul_sch;

		/**physical layer is called here and physical_layer_call is defined and declared in physical layer**/
		physical_layer_call(Ul_sch);
		/*return ul_sch;*/
	}
	else
	{
		printf("\ncrash in physical layer");
	}
}

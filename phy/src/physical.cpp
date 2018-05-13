#include <iostream>
#include "../../rrc/inc/rrc.h"
#include "../../rlc/inc/rlc.h"
#include "../../mac/inc/mac.h"
#include "../inc/physical.h"

void physical_layer_call(ul_sch_type mac_pdu)
/**mac_pdu is USLCH channel passed from MAC layer**/
{
    phy_sch_type Pusch;

    Pusch.phy_sdu=mac_pdu;

    if(mac_pdu.sch==ul_sch)
    {
        printf("\nUlsch passed to physical layer");

        Pusch.phy_channel=pusch;
    }

    else
    {
        printf("\ncrash in physical layer");

    }

}

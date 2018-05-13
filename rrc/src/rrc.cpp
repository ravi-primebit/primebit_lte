#include <iostream>
#include "../inc/rrc.h"
#include "../../rlc/inc/rlc.h"

/**RLC header is included because srb0_without security is defined in RLC,if you don't declare
	you will get implicit declaration error**/

void rrc_init()
{
    srb_info srb_0;
    /**created a variable srb_0 which will be have RRC message from UE RRC to eNB RRC or vice versa and SRB_0
      carries info from RRC to RLC**/

    srb_0.rrc_connection_request.establishment_cause = mt_Access;
    srb_0.rrc_connection_request.initial_ue_identity.randomValue=20;
    srb_0.rrc_type=rrc_connection_request;

    /**created a function srb0_without security to pass SRB0 to RLC layer and this function definition will be in RLC layer**/

    /**in below if condition if rrc_type is rrc_connection_request then srb0_without_security function is called
       or else it will call crash **/
    if((srb_0.rrc_type==rrc_connection_request))
    {
        srb_0.srb=srb0;
        srb0_without_security(srb_0);
    }
    else
    {
        printf("crash in rrc");
    }
}




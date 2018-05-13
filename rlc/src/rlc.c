#include<stdio.h>
#include "../rrc/rrc.h"
#include "rlc.h"
#include "../mac/mac.h"
#include "../sturb/stub.h"
void srb0_without_security(srb_info rrc_pdu)
{
	ccch_info UL_ccch;
    UL_ccch.rlc_sdu=rrc_pdu;

	/** here we created UL_ccch which will be passed to MAC layer and it will carry RRC message and type of ccch channel
	used by RLC**/

    /**in below condition if srb passed by RRC is SRB0 then mac layer will be called or else not**/

   if(rrc_pdu.srb==srb0)
   {
		/**allocating type of ccch used, to UL_ccch which will be useful for MAC layer to decode what channel
		is sent by RLC layer**/

	   UL_ccch.ccch=ul_ccch;

       printf("\nSRB0 is passed to rlc");

       /**calling mac_layer_call function and  it's definition and declaration is in mac layer**/
       /**passing Ul_ccch because CCCH is a channel between RLC and MAC**/

       mac_layer_call(UL_ccch);
   }
   else
   {
       printf("crash in mac layer");
   }


}

void rlc_stub(srb_to_add_type rlc_sdu)
{
    int srb0;
    srb0=rlc_sdu.srbidentity;
    printf("srb.identity=%d",rlc_sdu.srbidentity);
rrc_stub(srb0);
}

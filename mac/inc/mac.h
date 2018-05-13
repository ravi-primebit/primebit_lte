#ifndef MAC_H_INCLUDED
#define MAC_H_INCLUDED

void mac_layer_call(ccch_info);
typedef enum{

	ul_sch=0,
	dl_sch=1

}sch_type;

/**here created sch_type to inform physical layer which type of channel is used by MAC layer according to which PHYSICAL
layer will use corresponding PHYSICAL channel**/


typedef struct {

	sch_type sch;
	ccch_info mac_sdu;
/*extensions*/

}ul_sch_type;

/**ul_sch_type is ULSCH channel which will carry MAC info and type of sch used **/



#endif // MAC_H_INCLUDED


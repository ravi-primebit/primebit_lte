#ifndef RLC_H_INCLUDED
#define RLC_H_INCLUDED


typedef enum{
ul_ccch=0,
dl_ccch=1
}ccch_type;

/**here we created ccch_type to tell MAC which ccch is used,because based on that it uses corresponding
transport channel**/

typedef struct {

ccch_type ccch;
srb_info rlc_sdu;

}ccch_info;

/**ccch_info data type is for CCCH channel which will carry message (rlc_sdu) to receiver RLC and type
of ccch (ccch_type) to MAC**/


void srb0_without_security(srb_info rrc_pdu);

/**rrc_pdu is the value passed from rrc layer i.e SRB0  **/
/** srb0_without_security function is used to pass SRB0 from RRC layer to RLC layer**/


#endif // RLC_H_INCLUDED

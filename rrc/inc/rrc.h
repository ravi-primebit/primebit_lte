#ifndef RRC_H_INCLUDED
#define RRC_H_INCLUDED

#include <stdint-gcc.h>

typedef enum{
  emergency = 0x1,
  highPriorityAccess,
  mt_Access,
  mo_Signalling,
  mo_Data,
  spare1,
  spare2,
  establishment_cause_max=0xd

}establishment_cause_enum_type;

/**as we have only six values in establishment cause and we have select only one value
  we have taken establishment cause as enum type    **/

typedef struct {

  int8_t mmec;
  int32_t m_tmsi;

}s_tmsi_type;

/**s-tmsi is a combination of mmec+m-tmsi **/

typedef union {

  s_tmsi_type s_tmsi;
  int64_t randomValue;

}ue_identity_type;

/**in RRC Connection Request we send either S-TMSI or random value so we created
  ue_identity as union*/

typedef struct  {

  ue_identity_type initial_ue_identity;
  establishment_cause_enum_type establishment_cause;

}rrc_connection_request_type;

typedef enum {

  srb0=0,
  srb1=1,
  srb2=2

}srb_type;

/**we created srb_type to tell RLC which SRB has been transferred because based on the SRB transmitted by RRC
it selects corresponding logical channel**/

typedef enum {

  rrc_connection_request=0,
  rrc_connection_re_establishment=1,
  rrc_connecction_setup_complete=2,
  rrc_connection_re_establishment_complete=3
  #if 0
    rrc_connection_setup;
    rrc_connection_re-establishment_request;
    rrc_connection_re-establishment_reject;
    rrc_connection_reject;
  #endif

}rrc_type_for_srb;

/**we created rrc_type_for_srb to tell receiver what type of request is sent by ue**/

typedef union {

  rrc_connection_request_type rrc_connection_request;
  rrc_type_for_srb rrc_type;
  srb_type srb;
  #if 0
  rrc_conc_reestablishment_req_type rrc_conc_reestablishment_req;
  #endif // 0

}srb_info;

/**srb_0_type is data type which will carry RRC message(rrc_connection_request_type to receiver,and info for RLC which
  says what kind of info SRB0 is carrying**/

void rrc_init();

/**RRC_Init is a function used to pass SRB0 to RLC Layer**/


#endif // RRC_H_INCLUDED


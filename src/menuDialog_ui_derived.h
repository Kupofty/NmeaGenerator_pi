#ifndef __menuDialog_ui_derived__
#define __menuDialog_ui_derived__

#include "menuDialog_ui_base.h"


class DialogMenuEntry : public DialogMenuEntryBase
{
  public:
    DialogMenuEntry( wxWindow* parent );
    int m_updateVesselPositionChoice = 0;

  protected:
    void OnButtonClick_UpdateOwnShipPosition( wxCommandEvent& event ) override;
    void OnButtonClick_UpdateAisTargetPosition( wxCommandEvent& event ) override;
};

#endif // __menuDialog_ui_derived__

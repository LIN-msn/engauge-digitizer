/******************************************************************************************************
 * (C) 2020 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#include "CentipedeStateBuildPolar.h"
#include "CmdMediator.h"
#include "Logger.h"

CentipedeStateBuildPolar::CentipedeStateBuildPolar (CentipedeStateContext &context) :
  CentipedeStateAbstractBase (context)
{
}

CentipedeStateBuildPolar::~CentipedeStateBuildPolar ()
{
}

void CentipedeStateBuildPolar::begin ()
{
  LOG4CPP_DEBUG_S ((*mainCat)) << "CentipedeStateBuildPolar::begin";
}

void CentipedeStateBuildPolar::end ()
{
  LOG4CPP_DEBUG_S ((*mainCat)) << "CentipedeStateBuildPolar::end";
}

void CentipedeStateBuildPolar::handleKeyPress (CmdMediator &cmdMediator,
                                               Qt::Key key,
                                               bool atLeastOneSelectedItem)
{
}

void CentipedeStateBuildPolar::handleMouseMove (CmdMediator *cmdMediator,
                                                QPointF posScreen)
{
}
  
void CentipedeStateBuildPolar::handleMousePress (CmdMediator *cmdMediator,
                                                 QPointF posScreen)
{
}

void CentipedeStateBuildPolar::handleMouseRelease (CmdMediator *cmdMediator,
                                                   QPointF posScreen)
{
}

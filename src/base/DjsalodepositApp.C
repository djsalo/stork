#include "DjsalodepositApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<DjsalodepositApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

DjsalodepositApp::DjsalodepositApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  DjsalodepositApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  DjsalodepositApp::associateSyntax(_syntax, _action_factory);
}

DjsalodepositApp::~DjsalodepositApp()
{
}

void
DjsalodepositApp::registerApps()
{
  registerApp(DjsalodepositApp);
}

void
DjsalodepositApp::registerObjects(Factory & factory)
{
}

void
DjsalodepositApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}

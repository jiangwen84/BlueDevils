#include "BluedevilsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<BluedevilsApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

BluedevilsApp::BluedevilsApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  BluedevilsApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  BluedevilsApp::associateSyntax(_syntax, _action_factory);
}

BluedevilsApp::~BluedevilsApp()
{
}

// External entry point for dynamic application loading
extern "C" void BluedevilsApp__registerApps() { BluedevilsApp::registerApps(); }
void
BluedevilsApp::registerApps()
{
  registerApp(BluedevilsApp);
}

// External entry point for dynamic object registration
extern "C" void BluedevilsApp__registerObjects(Factory & factory) { BluedevilsApp::registerObjects(factory); }
void
BluedevilsApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void BluedevilsApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { BluedevilsApp::associateSyntax(syntax, action_factory); }
void
BluedevilsApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

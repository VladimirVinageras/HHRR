//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("GUI\uFormPrncipal.cpp", FormPrincipal);
USEFORM("GUI\uFormRegistroEmp.cpp", FormRegEmpresa);
USEFORM("GUI\uFormAltasMovimientos.cpp", FormAltasYMov);
USEFORM("GUI\uFormEstadoPlantilla.cpp", FormEstadoPlantilla);
USEFORM("GUI\uFondoSalario.cpp", FormFondoSalario);
USEFORM("GUI\uFormAcercaDe.cpp", FormAcercaDe);
USEFORM("GUI\uFormConfigurar.cpp", FormConfigurar);
USEFORM("GUI\uFormPlazasMenosOcupadas.cpp", FormPlazasMenosCubiertas);
USEFORM("GUI\uFormListadoNomina.cpp", FormListadoNomina);
USEFORM("GUI\FormBajasModificaciones.cpp", FormBajasModific);
USEFORM("GUI\uFormIncidencias.cpp", FormIncidencias);
USEFORM("GUI\uFormModificarRegistros.cpp", FormModificarRegistros);
USEFORM("GUI\uFormEliminarRegistros.cpp", FormEliminarRegistros);
USEFORM("GUI\uFormVerTrabajadores.cpp", FormVerTrabajadores);
USEFORM("GUI\uFormVerDepartamentos.cpp", FormVerDepartamentos);
USEFORM("GUI\uFormVerCargos.cpp", FormVerCargos);
USEFORM("GUI\uFormVerEmpresa.cpp", FormVerEmpresa);
USEFORM("GUI\uFormListadoJefesDpto.cpp", FormListadoJefesDpto);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
        Application->Initialize();
        Application->CreateForm(__classid(TFormPrincipal), &FormPrincipal);
                 Application->CreateForm(__classid(TFormRegEmpresa), &FormRegEmpresa);
                 Application->CreateForm(__classid(TFormAltasYMov), &FormAltasYMov);
                 Application->CreateForm(__classid(TFormEstadoPlantilla), &FormEstadoPlantilla);
                 Application->CreateForm(__classid(TFormFondoSalario), &FormFondoSalario);
                 Application->CreateForm(__classid(TFormAcercaDe), &FormAcercaDe);
                 Application->CreateForm(__classid(TFormConfigurar), &FormConfigurar);
                 Application->CreateForm(__classid(TFormPlazasMenosCubiertas), &FormPlazasMenosCubiertas);
                 Application->CreateForm(__classid(TFormListadoNomina), &FormListadoNomina);
                 Application->CreateForm(__classid(TFormBajasModific), &FormBajasModific);
                 Application->CreateForm(__classid(TFormIncidencias), &FormIncidencias);
                 Application->CreateForm(__classid(TFormModificarRegistros), &FormModificarRegistros);
                 Application->CreateForm(__classid(TFormEliminarRegistros), &FormEliminarRegistros);
                 Application->CreateForm(__classid(TFormVerTrabajadores), &FormVerTrabajadores);
                 Application->CreateForm(__classid(TFormVerDepartamentos), &FormVerDepartamentos);
                 Application->CreateForm(__classid(TFormVerCargos), &FormVerCargos);
                 Application->CreateForm(__classid(TFormVerEmpresa), &FormVerEmpresa);
                 Application->CreateForm(__classid(TFormListadoJefesDpto), &FormListadoJefesDpto);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------

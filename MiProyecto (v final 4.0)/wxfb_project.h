///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/choice.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Principal
///////////////////////////////////////////////////////////////////////////////
class Principal : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* ingreso_dni;
		wxButton* boton_ingreso_dni;
		wxButton* m_agregar;
		wxButton* m_tabla;
		wxButton* m_button17;
		wxButton* m_button9;

		// Virtual event handlers, override them in your derived class
		virtual void ClickIngresoDNI( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickTabla( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPlanes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Principal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Planes
///////////////////////////////////////////////////////////////////////////////
class Planes : public wxFrame
{
	private:

	protected:
		wxGrid* Tabla_P;
		wxButton* m_button20;
		wxButton* m_button23;
		wxButton* m_button22;
		wxButton* m_button21;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Planes( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Planes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PlanesModificar
///////////////////////////////////////////////////////////////////////////////
class PlanesModificar : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText24;
		wxTextCtrl* e_plan;
		wxStaticText* m_staticText25;
		wxTextCtrl* e_costo;
		wxButton* m_button25;
		wxButton* m_button26;

		// Virtual event handlers, override them in your derived class
		virtual void ClickModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		PlanesModificar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~PlanesModificar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PlanesAgregar
///////////////////////////////////////////////////////////////////////////////
class PlanesAgregar : public wxFrame
{
	private:

	protected:
		wxStaticText* asdasda;
		wxTextCtrl* e_plan;
		wxStaticText* Asdasas;
		wxTextCtrl* e_costo;
		wxButton* Agregar;
		wxButton* m_button23;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		PlanesAgregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~PlanesAgregar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Agregar
///////////////////////////////////////////////////////////////////////////////
class Agregar : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText3;
		wxTextCtrl* entrada_nombre;
		wxStaticText* m_staticText10;
		wxTextCtrl* entrada_apellido;
		wxStaticText* m_staticText11;
		wxChoice* seleccion_sexo;
		wxStaticText* m_staticText171;
		wxTextCtrl* entrada_telefono;
		wxStaticText* m_staticText32;
		wxTextCtrl* entrada_dni;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText16;
		wxChoice* seleccion_plan;
		wxStaticText* m_staticText33;
		wxTextCtrl* entrada_mail;
		wxStaticText* m_staticText34;
		wxTextCtrl* entrada_dia;
		wxStaticText* m_staticText14;
		wxTextCtrl* entrada_mes;
		wxStaticText* m_staticText15;
		wxTextCtrl* entrada_anio;
		wxStaticText* m_staticText19;
		wxButton* m_aceptar;
		wxButton* m_cancelar;

		// Virtual event handlers, override them in your derived class
		virtual void SeleccionPlanes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Agregar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Agregar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Tabla
///////////////////////////////////////////////////////////////////////////////
class Tabla : public wxFrame
{
	private:

	protected:
		wxTextCtrl* entrada_buscar;
		wxButton* m_button10;
		wxStaticText* m_staticText15;
		wxChoice* seleccion_orden_tabla;
		wxButton* m_button101;
		wxGrid* m_grilla;
		wxChoice* seleccion_filtro;
		wxButton* m_button11;
		wxButton* m_button20;
		wxButton* m_button12;
		wxButton* m_button14;

		// Virtual event handlers, override them in your derived class
		virtual void ClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickOrdenar( wxCommandEvent& event ) { event.Skip(); }
		virtual void SeleccionPlanes( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickFiltrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickVerDatos( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Tabla( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Tabla();

};

///////////////////////////////////////////////////////////////////////////////
/// Class VerDatos
///////////////////////////////////////////////////////////////////////////////
class VerDatos : public wxFrame
{
	private:

	protected:
		wxGrid* m_grilla;
		wxButton* m_button19;
		wxButton* m_button12;

		// Virtual event handlers, override them in your derived class
		virtual void ClickModificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickSalir( wxCommandEvent& event ) { event.Skip(); }


	public:

		VerDatos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 806,223 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~VerDatos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Modificar
///////////////////////////////////////////////////////////////////////////////
class Modificar : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText15;
		wxTextCtrl* e_dni;
		wxStaticText* m_staticText16;
		wxTextCtrl* e_telefono;
		wxStaticText* m_staticText151;
		wxChoice* seleccion_sexo;
		wxStaticText* m_staticText161;
		wxTextCtrl* e_nombre;
		wxStaticText* m_staticText29;
		wxTextCtrl* e_apellido;
		wxStaticText* m_staticText152;
		wxTextCtrl* e_mail;
		wxStaticText* m_staticText162;
		wxTextCtrl* e_plan;
		wxButton* m_button17;
		wxButton* m_button18;

		// Virtual event handlers, override them in your derived class
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Modificar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Modificar();

};


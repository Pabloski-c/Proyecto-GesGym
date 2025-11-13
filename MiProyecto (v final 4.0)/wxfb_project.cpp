///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Principal::Principal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );


	bSizer2->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("PablitoGim"), wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetFont( wxFont( 48, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Consolas") ) );

	bSizer2->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	ingreso_dni = new wxTextCtrl( this, wxID_ANY, wxT("Ingrese DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( ingreso_dni, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	boton_ingreso_dni = new wxButton( this, wxID_ANY, wxT("Ingresar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( boton_ingreso_dni, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer16, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_agregar, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_tabla = new wxButton( this, wxID_ANY, wxT("Tabla"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_tabla, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button17 = new wxButton( this, wxID_ANY, wxT("Planes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button17, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button9 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button9, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer2->Add( bSizer3, 1, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	boton_ingreso_dni->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickIngresoDNI ), NULL, this );
	m_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickAgregar ), NULL, this );
	m_tabla->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickTabla ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickPlanes ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickSalir ), NULL, this );
}

Principal::~Principal()
{
	// Disconnect Events
	boton_ingreso_dni->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickIngresoDNI ), NULL, this );
	m_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickAgregar ), NULL, this );
	m_tabla->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickTabla ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickPlanes ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::ClickSalir ), NULL, this );

}

Planes::Planes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	Tabla_P = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	Tabla_P->CreateGrid( 0, 2 );
	Tabla_P->EnableEditing( true );
	Tabla_P->EnableGridLines( true );
	Tabla_P->EnableDragGridSize( false );
	Tabla_P->SetMargins( 0, 0 );

	// Columns
	Tabla_P->EnableDragColMove( false );
	Tabla_P->EnableDragColSize( true );
	Tabla_P->SetColLabelValue( 0, wxT("Planes") );
	Tabla_P->SetColLabelValue( 1, wxT("Precios") );
	Tabla_P->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	Tabla_P->EnableDragRowSize( true );
	Tabla_P->SetRowLabelSize( 0 );
	Tabla_P->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	Tabla_P->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer21->Add( Tabla_P, 0, wxALL, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxHORIZONTAL );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button20, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button23, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button22 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button22, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button21 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_button21, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer21->Add( bSizer22, 0, wxALIGN_RIGHT|wxALL, 5 );


	this->SetSizer( bSizer21 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickAgregar ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickModificar ), NULL, this );
	m_button22->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickEliminar ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickSalir ), NULL, this );
}

Planes::~Planes()
{
	// Disconnect Events
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickAgregar ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickModificar ), NULL, this );
	m_button22->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickEliminar ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Planes::ClickSalir ), NULL, this );

}

PlanesModificar::PlanesModificar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Plan:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer26->Add( m_staticText24, 0, wxALL, 5 );

	e_plan = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( e_plan, 0, wxALL, 5 );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Costo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer26->Add( m_staticText25, 0, wxALL, 5 );

	e_costo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( e_costo, 0, wxALL, 5 );


	bSizer25->Add( bSizer26, 1, wxEXPAND, 5 );

	m_button25 = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_button25, 0, wxALL, 5 );

	m_button26 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_button26, 0, wxALL, 5 );


	this->SetSizer( bSizer25 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button25->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesModificar::ClickModificar ), NULL, this );
	m_button26->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesModificar::ClickSalir ), NULL, this );
}

PlanesModificar::~PlanesModificar()
{
	// Disconnect Events
	m_button25->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesModificar::ClickModificar ), NULL, this );
	m_button26->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesModificar::ClickSalir ), NULL, this );

}

PlanesAgregar::PlanesAgregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );

	asdasda = new wxStaticText( this, wxID_ANY, wxT("Plan:"), wxDefaultPosition, wxDefaultSize, 0 );
	asdasda->Wrap( -1 );
	bSizer24->Add( asdasda, 0, wxALL, 5 );

	e_plan = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( e_plan, 0, wxALL, 5 );

	Asdasas = new wxStaticText( this, wxID_ANY, wxT("Costo:"), wxDefaultPosition, wxDefaultSize, 0 );
	Asdasas->Wrap( -1 );
	bSizer24->Add( Asdasas, 0, wxALL, 5 );

	e_costo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( e_costo, 0, wxALL, 5 );


	bSizer23->Add( bSizer24, 1, wxEXPAND, 5 );

	Agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( Agregar, 0, wxALL, 5 );

	m_button23 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( m_button23, 0, wxALL, 5 );


	this->SetSizer( bSizer23 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	Agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesAgregar::ClickAgregar ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesAgregar::ClickSalir ), NULL, this );
}

PlanesAgregar::~PlanesAgregar()
{
	// Disconnect Events
	Agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesAgregar::ClickAgregar ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PlanesAgregar::ClickSalir ), NULL, this );

}

Agregar::Agregar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer5->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer5->Add( entrada_nombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer5->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer5->Add( entrada_apellido, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Sexo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer51->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString seleccion_sexoChoices[] = { wxT("Masculino"), wxT("Femenino"), wxT("Otro") };
	int seleccion_sexoNChoices = sizeof( seleccion_sexoChoices ) / sizeof( wxString );
	seleccion_sexo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, seleccion_sexoNChoices, seleccion_sexoChoices, 0 );
	seleccion_sexo->SetSelection( 0 );
	bSizer51->Add( seleccion_sexo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText171 = new wxStaticText( this, wxID_ANY, wxT("Telefono (Sin CDZ):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText171->Wrap( -1 );
	bSizer51->Add( m_staticText171, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_telefono = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer51->Add( entrada_telefono, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer52->Add( m_staticText32, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 150,-1 ), 0 );
	bSizer52->Add( entrada_dni, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("(Solo numeros)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer52->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Plan:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer52->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxArrayString seleccion_planChoices;
	seleccion_plan = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, seleccion_planChoices, 0 );
	seleccion_plan->SetSelection( 0 );
	bSizer52->Add( seleccion_plan, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer52, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("e-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer53->Add( m_staticText33, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 250,-1 ), 0 );
	bSizer53->Add( entrada_mail, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer53, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Ingreso"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer54->Add( m_staticText34, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( entrada_dia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer54->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( entrada_mes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer54->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	entrada_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( entrada_anio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer54, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("CDZ = Codigo de Zona"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer55->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_aceptar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_aceptar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_cancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( m_cancelar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer55, 1, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	seleccion_plan->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Agregar::SeleccionPlanes ), NULL, this );
	m_aceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Agregar::ClickAceptar ), NULL, this );
	m_cancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Agregar::ClickCancelar ), NULL, this );
}

Agregar::~Agregar()
{
	// Disconnect Events
	seleccion_plan->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Agregar::SeleccionPlanes ), NULL, this );
	m_aceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Agregar::ClickAceptar ), NULL, this );
	m_cancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Agregar::ClickCancelar ), NULL, this );

}

Tabla::Tabla( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );

	entrada_buscar = new wxTextCtrl( this, wxID_ANY, wxT("Ingrese Nombre o Dni"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( entrada_buscar, 1, wxALL, 5 );

	m_button10 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button10, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Ordenar Tabla:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer14->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString seleccion_orden_tablaChoices[] = { wxT("Apellido"), wxT("DNI"), wxT("Plan") };
	int seleccion_orden_tablaNChoices = sizeof( seleccion_orden_tablaChoices ) / sizeof( wxString );
	seleccion_orden_tabla = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, seleccion_orden_tablaNChoices, seleccion_orden_tablaChoices, 0 );
	seleccion_orden_tabla->SetSelection( 0 );
	bSizer14->Add( seleccion_orden_tabla, 0, wxALL, 5 );

	m_button101 = new wxButton( this, wxID_ANY, wxT("Ordenar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button101, 0, wxALL, 5 );


	bSizer13->Add( bSizer14, 0, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 5 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 143 );
	m_grilla->SetColSize( 1, 84 );
	m_grilla->SetColSize( 2, 71 );
	m_grilla->SetColSize( 3, 71 );
	m_grilla->SetColSize( 4, 84 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Apellido y Nombre") );
	m_grilla->SetColLabelValue( 1, wxT("DNI") );
	m_grilla->SetColLabelValue( 2, wxT("Plan") );
	m_grilla->SetColLabelValue( 3, wxT("Telefono") );
	m_grilla->SetColLabelValue( 4, wxT("Estado") );
	m_grilla->SetColLabelSize( 30 );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer13->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	wxArrayString seleccion_filtroChoices;
	seleccion_filtro = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, seleccion_filtroChoices, 0 );
	seleccion_filtro->SetSelection( 0 );
	bSizer15->Add( seleccion_filtro, 0, wxALL, 5 );

	m_button11 = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Datos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button20, 0, wxALL, 5 );

	m_button12 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button14 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_button14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer13->Add( bSizer15, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickBuscar ), NULL, this );
	m_button101->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickOrdenar ), NULL, this );
	seleccion_filtro->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Tabla::SeleccionPlanes ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickFiltrar ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickVerDatos ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickEliminar ), NULL, this );
	m_button14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickSalir ), NULL, this );
}

Tabla::~Tabla()
{
	// Disconnect Events
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickBuscar ), NULL, this );
	m_button101->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickOrdenar ), NULL, this );
	seleccion_filtro->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Tabla::SeleccionPlanes ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickFiltrar ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickVerDatos ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickEliminar ), NULL, this );
	m_button14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Tabla::ClickSalir ), NULL, this );

}

VerDatos::VerDatos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 7 );
	m_grilla->EnableEditing( true );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 169 );
	m_grilla->SetColSize( 1, 89 );
	m_grilla->SetColSize( 2, 80 );
	m_grilla->SetColSize( 3, 83 );
	m_grilla->SetColSize( 4, 70 );
	m_grilla->SetColSize( 5, 182 );
	m_grilla->SetColSize( 6, 80 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Apellido y Nombre") );
	m_grilla->SetColLabelValue( 1, wxT("DNI") );
	m_grilla->SetColLabelValue( 2, wxT("Sexo") );
	m_grilla->SetColLabelValue( 3, wxT("Plan") );
	m_grilla->SetColLabelValue( 4, wxT("Telefono") );
	m_grilla->SetColLabelValue( 5, wxT("E-mail") );
	m_grilla->SetColLabelValue( 6, wxT("Estado") );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelValue( 0, wxT("Apellido y Nombre") );
	m_grilla->SetRowLabelValue( 1, wxT("DNI") );
	m_grilla->SetRowLabelValue( 2, wxT("Sexo") );
	m_grilla->SetRowLabelValue( 3, wxT("Telefono") );
	m_grilla->SetRowLabelValue( 4, wxT("E-mail") );
	m_grilla->SetRowLabelValue( 5, wxT("Fecha de Ingreso") );
	m_grilla->SetRowLabelValue( 6, wxT("Plan") );
	m_grilla->SetRowLabelSize( 0 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer13->Add( m_grilla, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Modificar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button19, 0, wxALL, 5 );

	m_button12 = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( m_button12, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer13->Add( bSizer14, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer13 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VerDatos::ClickModificar ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VerDatos::ClickSalir ), NULL, this );
}

VerDatos::~VerDatos()
{
	// Disconnect Events
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VerDatos::ClickModificar ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VerDatos::ClickSalir ), NULL, this );

}

Modificar::Modificar( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer17->Add( m_staticText15, 0, wxALL, 5 );

	e_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( e_dni, 0, wxALL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer17->Add( m_staticText16, 0, wxALL, 5 );

	e_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( e_telefono, 0, wxALL, 5 );


	bSizer16->Add( bSizer17, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText151 = new wxStaticText( this, wxID_ANY, wxT("Sexo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	bSizer171->Add( m_staticText151, 0, wxALL, 5 );

	wxString seleccion_sexoChoices[] = { wxT("Masculino"), wxT("Femenino"), wxT("Otro") };
	int seleccion_sexoNChoices = sizeof( seleccion_sexoChoices ) / sizeof( wxString );
	seleccion_sexo = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, seleccion_sexoNChoices, seleccion_sexoChoices, 0 );
	seleccion_sexo->SetSelection( 0 );
	bSizer171->Add( seleccion_sexo, 0, wxALL, 5 );

	m_staticText161 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText161->Wrap( -1 );
	bSizer171->Add( m_staticText161, 0, wxALL, 5 );

	e_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( e_nombre, 0, wxALL, 5 );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer171->Add( m_staticText29, 0, wxALL, 5 );

	e_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( e_apellido, 0, wxALL, 5 );


	bSizer16->Add( bSizer171, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer172;
	bSizer172 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText152 = new wxStaticText( this, wxID_ANY, wxT("Mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText152->Wrap( -1 );
	bSizer172->Add( m_staticText152, 0, wxALL, 5 );

	e_mail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer172->Add( e_mail, 0, wxALL, 5 );

	m_staticText162 = new wxStaticText( this, wxID_ANY, wxT("Plan:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText162->Wrap( -1 );
	bSizer172->Add( m_staticText162, 0, wxALL, 5 );

	e_plan = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer172->Add( e_plan, 0, wxALL, 5 );


	bSizer16->Add( bSizer172, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer173;
	bSizer173 = new wxBoxSizer( wxHORIZONTAL );

	m_button17 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer173->Add( m_button17, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button18 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer173->Add( m_button18, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer16->Add( bSizer173, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer16 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Modificar::ClickAceptar ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Modificar::ClickCancelar ), NULL, this );
}

Modificar::~Modificar()
{
	// Disconnect Events
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Modificar::ClickAceptar ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Modificar::ClickCancelar ), NULL, this );

}

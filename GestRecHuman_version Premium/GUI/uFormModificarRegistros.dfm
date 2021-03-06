object FormModificarRegistros: TFormModificarRegistros
  Left = 4
  Top = 236
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Administraci'#243'n - Modificar del Registro'
  ClientHeight = 368
  ClientWidth = 571
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    7777777777777777110000000110000078888888888888871111111111110000
    08777FFFFFF77780777777777771000000007777777700007777778888830777
    77777777722777227777777777837888888888882AA282AA2887778888837888
    8888888882288822888777777783788888888888888888888887778888837866
    6666666666666666668777777783780000000000000000000087778888877800
    0000000000000000008777777787780000000000000000000087778888877800
    0000000000000000008777888887780000FFFFFFFFFFFF000087777777877800
    00FF8888F8888F00008788888787780000FFFFFFFFFFFF000087888887877800
    00FFFFFFFFFFFF00008788FFF7F7780000FFFFFFFFFFFF00008788FFF7F77800
    00CCCCCCCCCCCC00008788FFB7F778000000000000000000008788FFF7F77800
    00000000000000000087777777F778000000000000000000008788FFF7F77800
    000000000000000000878FFFB7F7788888888888888888888887FFFFF7F70777
    77777777777777777777777777F700000000000000000007FFFFFFFFFFF70000
    0000000000000007FFFFFFFFFFF7000000000000000000007777777777700000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFFFFFFFFFFF00003F9F0000000F8000000FF00E00080000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    00000000000080000000FFFFE000FFFFE000FFFFF001FFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 16
    Top = 16
    Width = 537
    Height = 313
    ActivePage = TabSheet2
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Modificar Cargos'
      OnShow = TabSheet1Show
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label5: TLabel
        Left = 8
        Top = 10
        Width = 195
        Height = 13
        Caption = 'Seleccione el cargo que desea modificar:'
      end
      object GroupBox2: TGroupBox
        Left = 295
        Top = 24
        Width = 224
        Height = 169
        Caption = 'Modificaciones'
        TabOrder = 3
        object Label1: TLabel
          Left = 20
          Top = 32
          Width = 78
          Height = 13
          AutoSize = False
          Caption = 'Nuevo Nombre:'
        end
        object Label2: TLabel
          Left = 20
          Top = 97
          Width = 70
          Height = 13
          Caption = 'Nuevo Salario:'
        end
        object Edit1: TEdit
          Left = 20
          Top = 48
          Width = 181
          Height = 21
          TabOrder = 0
          OnKeyPress = Edit1KeyPress
        end
        object Edit2: TEdit
          Left = 20
          Top = 112
          Width = 181
          Height = 21
          TabOrder = 1
          OnKeyPress = Edit2KeyPress
        end
      end
      object ListView1: TListView
        Left = 8
        Top = 25
        Width = 274
        Height = 248
        Columns = <
          item
            Caption = 'Nombre'
            Width = 150
          end
          item
            Caption = 'Salario'
            Width = 120
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        ViewStyle = vsReport
        OnClick = ListView1Click
      end
      object btnAceptarCargo: TButton
        Left = 336
        Top = 210
        Width = 73
        Height = 25
        Caption = 'Aceptar'
        TabOrder = 1
        OnClick = btnAceptarCargoClick
      end
      object btnCancelar: TButton
        Left = 416
        Top = 210
        Width = 73
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 2
        OnClick = btnCancelarClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Modificar Departamentos'
      ImageIndex = 1
      OnShow = TabSheet2Show
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Label3: TLabel
        Left = 237
        Top = 30
        Width = 75
        Height = 13
        Caption = 'Nuevo Nombre:'
      end
      object Label4: TLabel
        Left = 238
        Top = 56
        Width = 71
        Height = 13
        Caption = 'Nuevo C'#243'digo:'
      end
      object Label8: TLabel
        Left = 11
        Top = 15
        Width = 189
        Height = 13
        Caption = 'Seleccione el departamento a modificar:'
      end
      object ListView2: TListView
        Left = 11
        Top = 30
        Width = 212
        Height = 243
        Columns = <
          item
            Caption = 'Nombre'
            Width = 110
          end
          item
            Caption = 'C'#243'digo'
            Width = 98
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        ViewStyle = vsReport
        OnClick = ListView2Click
      end
      object Edit3: TEdit
        Left = 320
        Top = 27
        Width = 106
        Height = 21
        TabOrder = 1
        OnKeyPress = Edit3KeyPress
      end
      object Edit4: TEdit
        Left = 320
        Top = 54
        Width = 106
        Height = 21
        TabOrder = 2
      end
      object GroupBox1: TGroupBox
        Left = 238
        Top = 84
        Width = 279
        Height = 190
        Caption = 'Cargos'
        TabOrder = 3
        object Label6: TLabel
          Left = 154
          Top = 98
          Width = 88
          Height = 13
          Caption = 'Plazas Aprobadas:'
        end
        object Label7: TLabel
          Left = 15
          Top = 98
          Width = 106
          Height = 13
          Caption = 'Cargos de la Empresa:'
        end
        object RadioGroup1: TRadioGroup
          Left = 15
          Top = 28
          Width = 248
          Height = 49
          Caption = 'Opciones'
          Columns = 2
          Items.Strings = (
            'Agregar Cargo'
            'Modificar Cargo')
          TabOrder = 0
          OnClick = RadioGroup1Click
        end
        object Edit6: TEdit
          Left = 154
          Top = 116
          Width = 107
          Height = 21
          TabOrder = 1
          OnKeyPress = Edit6KeyPress
        end
        object btnAceptarRadioGroup: TButton
          Left = 73
          Top = 152
          Width = 73
          Height = 25
          Caption = 'Aceptar'
          TabOrder = 2
          OnClick = btnAceptarRadioGroupClick
        end
        object btnCancelarDpto: TButton
          Left = 151
          Top = 152
          Width = 73
          Height = 25
          Caption = 'Cancelar'
          TabOrder = 3
        end
        object ComboBox1: TComboBox
          Left = 15
          Top = 116
          Width = 130
          Height = 21
          Style = csDropDownList
          TabOrder = 4
          OnChange = ComboBox1Change
        end
      end
      object btnAceptar: TButton
        Left = 440
        Top = 27
        Width = 73
        Height = 25
        Caption = 'Aceptar'
        TabOrder = 4
        OnClick = btnAceptarClick
      end
    end
  end
  object btnCerrar: TButton
    Left = 248
    Top = 336
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnCerrarClick
  end
end

object FormBajasModific: TFormBajasModific
  Left = 333
  Top = 109
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Plantilla de Trabajadores - Bajas y Modficaciones'
  ClientHeight = 389
  ClientWidth = 441
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
    Width = 409
    Height = 336
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Dar Baja'
      OnShow = TabSheet1Show
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object GroupBox3: TGroupBox
        Left = 9
        Top = 8
        Width = 283
        Height = 289
        Caption = 'Buscar trabajador'
        TabOrder = 0
        object Label3: TLabel
          Left = 12
          Top = 26
          Width = 101
          Height = 13
          Caption = 'Numero de identidad:'
        end
        object Edit2: TEdit
          Left = 12
          Top = 42
          Width = 169
          Height = 21
          MaxLength = 11
          TabOrder = 0
          OnKeyPress = Edit2KeyPress
        end
        object bitbtnBuscarTrab: TBitBtn
          Left = 194
          Top = 38
          Width = 75
          Height = 26
          Caption = 'Buscar'
          DoubleBuffered = True
          Glyph.Data = {
            E6040000424DE604000000000000360000002800000014000000140000000100
            180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
            0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000FF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00000000FFFFFF0000000000800000800000FF000000FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            0000000000000000800000FF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF000000808080C0C0C0C0C0C0FFFFFFC0C0C0C0C0C080
            8080000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFF000000C0C0C0FFFF00808080808080FFFF00FFFFFFC0C0C00000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000808080C0C0C0FFFFFFC0C0C0FFFF00FFFFFFFFFF00C0C0C0808080000000
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0
            C0FFFFFFFFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00000000000000FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0808080000000FFFFFF000000FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0FFFFFFFF
            FFFFFFFFFFFFFF00C0C0C0808080000000808080000000FFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080C0C0C0FFFFFFFFFF
            FF000000808080000000808080000000808080000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            000000808080000000808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000080
            8080808080FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
            00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF}
          ParentDoubleBuffered = False
          TabOrder = 1
          OnClick = bitbtnBuscarTrabClick
        end
        object GroupBox4: TGroupBox
          Left = 12
          Top = 74
          Width = 258
          Height = 201
          Caption = 'Verifique los datos'
          TabOrder = 2
          object StaticText2: TStaticText
            Left = 62
            Top = 20
            Width = 187
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 0
          end
          object StaticText7: TStaticText
            Left = 8
            Top = 44
            Width = 53
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Telefono:'
            TabOrder = 1
          end
          object StaticText8: TStaticText
            Left = 62
            Top = 44
            Width = 187
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 2
          end
          object Memo1: TMemo
            Left = 8
            Top = 68
            Width = 241
            Height = 49
            Color = clBtnFace
            Lines.Strings = (
              'Direccion particular:')
            ReadOnly = True
            TabOrder = 3
          end
          object StaticText3: TStaticText
            Left = 8
            Top = 121
            Width = 109
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Departamento actual:'
            TabOrder = 4
          end
          object StaticText4: TStaticText
            Left = 118
            Top = 121
            Width = 130
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 5
          end
          object StaticText6: TStaticText
            Left = 8
            Top = 145
            Width = 109
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Cargo que ocupa:'
            TabOrder = 6
          end
          object StaticText5: TStaticText
            Left = 118
            Top = 145
            Width = 130
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 7
          end
          object StaticText9: TStaticText
            Left = 8
            Top = 169
            Width = 109
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Salario:'
            TabOrder = 8
          end
          object StaticText10: TStaticText
            Left = 118
            Top = 169
            Width = 130
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            TabOrder = 9
          end
          object StaticText1: TStaticText
            Left = 8
            Top = 20
            Width = 53
            Height = 20
            AutoSize = False
            BevelInner = bvSpace
            BevelKind = bkFlat
            BevelOuter = bvSpace
            BorderStyle = sbsSunken
            Caption = 'Nombre:'
            TabOrder = 10
          end
        end
      end
      object btnEliminar: TButton
        Left = 302
        Top = 16
        Width = 72
        Height = 25
        Caption = 'Eliminar'
        Enabled = False
        TabOrder = 1
        OnClick = btnEliminarClick
      end
      object btnCancelar: TButton
        Left = 302
        Top = 48
        Width = 72
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 2
        OnClick = btnCancelarClick
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Modificar'
      ImageIndex = 1
      OnEnter = TabSheet2Enter
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object btnAceptar: TButton
        Left = 318
        Top = 16
        Width = 73
        Height = 25
        Caption = 'Aceptar'
        Enabled = False
        TabOrder = 0
        OnClick = btnAceptarClick
      end
      object btnCancelar1: TButton
        Left = 318
        Top = 48
        Width = 73
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 1
        OnClick = btnCancelar1Click
      end
      object GroupBox1: TGroupBox
        Left = 6
        Top = 1
        Width = 302
        Height = 301
        Caption = 'Buscar trabajador'
        TabOrder = 2
        object Label2: TLabel
          Left = 10
          Top = 22
          Width = 101
          Height = 13
          Caption = 'Numero de identidad:'
        end
        object bitbtnBuscarTrab1: TBitBtn
          Left = 201
          Top = 36
          Width = 75
          Height = 26
          Caption = 'Buscar'
          DoubleBuffered = True
          Glyph.Data = {
            E6040000424DE604000000000000360000002800000014000000140000000100
            180000000000B0040000C40E0000C40E00000000000000000000FFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000
            0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000800000800000FF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
            00000000FFFFFF0000000000800000800000FF000000FFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            0000000000000000800000FF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF000000808080C0C0C0C0C0C0FFFFFFC0C0C0C0C0C080
            8080000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFF000000C0C0C0FFFF00808080808080FFFF00FFFFFFC0C0C00000
            00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
            0000808080C0C0C0FFFFFFC0C0C0FFFF00FFFFFFFFFF00C0C0C0808080000000
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0
            C0FFFFFFFFFFFFFFFF00FFFFFFFFFF00FFFFFFFFFF00000000000000FFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0808080000000FFFFFF000000FFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000C0C0C0FFFFFFFF
            FFFFFFFFFFFFFF00C0C0C0808080000000808080000000FFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000808080C0C0C0FFFFFFFFFF
            FF000000808080000000808080000000808080000000000000FFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000808080C0C0C0808080
            000000808080000000808080FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000080
            8080808080FFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000
            00FFFFFFFFFFFF000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFF000000FFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
            FFFFFFFFFFFFFFFFFFFF}
          ParentDoubleBuffered = False
          TabOrder = 0
          OnClick = bitbtnBuscarTrab1Click
        end
        object GroupBox2: TGroupBox
          Left = 10
          Top = 69
          Width = 282
          Height = 222
          Caption = 'Modificaciones'
          TabOrder = 1
          object Bevel2: TBevel
            Left = 8
            Top = 153
            Width = 265
            Height = 60
            Shape = bsFrame
            Style = bsRaised
          end
          object Label5: TLabel
            Left = 8
            Top = 22
            Width = 93
            Height = 13
            Caption = 'Nombre y Apellidos:'
          end
          object Label8: TLabel
            Left = 8
            Top = 65
            Width = 45
            Height = 13
            Caption = 'Telefono:'
          end
          object Label7: TLabel
            Left = 8
            Top = 107
            Width = 94
            Height = 13
            Caption = 'Direccion particular:'
          end
          object Label1: TLabel
            Left = 110
            Top = 164
            Width = 104
            Height = 13
            Caption = 'Salario por resolucion:'
          end
          object Edit3: TEdit
            Left = 8
            Top = 38
            Width = 265
            Height = 21
            Color = clBtnFace
            Enabled = False
            TabOrder = 0
          end
          object Edit6: TEdit
            Left = 8
            Top = 81
            Width = 265
            Height = 21
            Color = clBtnFace
            Enabled = False
            MaxLength = 12
            TabOrder = 1
            OnKeyPress = Edit6KeyPress
          end
          object Edit5: TEdit
            Left = 8
            Top = 123
            Width = 265
            Height = 21
            Color = clBtnFace
            Enabled = False
            TabOrder = 2
          end
          object CheckBox1: TCheckBox
            Left = 23
            Top = 180
            Width = 79
            Height = 17
            Caption = 'Resolucion'
            Color = clBtnFace
            Enabled = False
            ParentColor = False
            TabOrder = 3
            OnClick = CheckBox1Click
          end
          object Edit1: TEdit
            Left = 110
            Top = 179
            Width = 148
            Height = 21
            Color = clBtnFace
            Enabled = False
            TabOrder = 4
            OnKeyPress = Edit1KeyPress
          end
        end
        object Edit7: TEdit
          Left = 10
          Top = 38
          Width = 175
          Height = 21
          MaxLength = 11
          TabOrder = 2
          OnKeyPress = Edit7KeyPress
        end
      end
    end
  end
  object btnCerrar: TButton
    Left = 191
    Top = 358
    Width = 75
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnCerrarClick
  end
end

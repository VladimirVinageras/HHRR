object FormEliminarRegistros: TFormEliminarRegistros
  Left = 570
  Top = 99
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Administracion - Eliminar del Registro'
  ClientHeight = 407
  ClientWidth = 538
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
  Scaled = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 16
    Width = 521
    Height = 356
    ActivePage = TabSheet2
    TabIndex = 1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'Eliminar Cargos'
      OnShow = TabSheet1Show
      object Bevel1: TBevel
        Left = 8
        Top = 8
        Width = 417
        Height = 311
      end
      object Label1: TLabel
        Left = 176
        Top = 76
        Width = 135
        Height = 13
        Caption = 'Seleccione el departamento:'
      end
      object Label2: TLabel
        Left = 21
        Top = 128
        Width = 188
        Height = 13
        Caption = 'Seleccione el cargo que desea eliminar:'
      end
      object Label4: TLabel
        Left = 181
        Top = 24
        Width = 188
        Height = 13
        Caption = 'Seleccione el cargo que desea eliminar:'
      end
      object RadioGroup1: TRadioGroup
        Left = 21
        Top = 24
        Width = 145
        Height = 89
        Caption = 'Eliminar cargos'
        Items.Strings = (
          'de la empresa'
          'de un departamento')
        TabOrder = 0
        OnClick = RadioGroup1Click
      end
      object btnEliminar: TButton
        Left = 434
        Top = 16
        Width = 73
        Height = 25
        Caption = 'Eliminar'
        Enabled = False
        TabOrder = 1
        OnClick = btnEliminarClick
      end
      object btnCancelar: TButton
        Left = 434
        Top = 48
        Width = 73
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 2
        OnClick = btnCancelarClick
      end
      object ComboBox1: TComboBox
        Left = 176
        Top = 92
        Width = 233
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 3
        OnChange = ComboBox1Change
      end
      object ListView1: TListView
        Left = 21
        Top = 148
        Width = 390
        Height = 158
        Columns = <
          item
            Caption = 'Cargo'
            Width = 131
          end
          item
            Alignment = taCenter
            Caption = 'Salario'
            Width = 55
          end
          item
            Alignment = taCenter
            Caption = 'Plazas Aprobadas'
            Width = 100
          end
          item
            Alignment = taCenter
            Caption = 'Plazas Ocupadas'
            Width = 100
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 4
        ViewStyle = vsReport
        OnSelectItem = ListView1SelectItem
      end
      object ListView3: TListView
        Left = 180
        Top = 43
        Width = 229
        Height = 265
        Columns = <
          item
            Caption = 'Cargo'
            Width = 150
          end
          item
            Alignment = taCenter
            Caption = 'Salario'
            Width = 75
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 5
        ViewStyle = vsReport
        OnSelectItem = ListView3SelectItem
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Eliminar Departamentos'
      ImageIndex = 1
      OnShow = TabSheet2Show
      object Bevel2: TBevel
        Left = 8
        Top = 8
        Width = 417
        Height = 311
      end
      object Label3: TLabel
        Left = 23
        Top = 18
        Width = 226
        Height = 13
        Caption = 'Seleccione el departamento que desea eliminar:'
      end
      object btnEliminarDep: TButton
        Left = 434
        Top = 16
        Width = 73
        Height = 25
        Caption = 'Eliminar'
        TabOrder = 0
        OnClick = btnEliminarDepClick
      end
      object btnCancelarDep: TButton
        Left = 434
        Top = 48
        Width = 73
        Height = 25
        Caption = 'Cancelar'
        TabOrder = 1
        OnClick = btnCancelarDepClick
      end
      object ListView2: TListView
        Left = 23
        Top = 37
        Width = 387
        Height = 269
        Columns = <
          item
            Caption = 'Nombre'
            Width = 122
          end
          item
            Caption = 'Codigo'
            Width = 106
          end
          item
            Caption = 'Jefe de Departamento'
            Width = 155
          end>
        GridLines = True
        ReadOnly = True
        RowSelect = True
        TabOrder = 2
        ViewStyle = vsReport
        OnSelectItem = ListView2SelectItem
      end
    end
  end
  object btnCerrar: TButton
    Left = 232
    Top = 377
    Width = 73
    Height = 25
    Caption = 'Cerrar'
    TabOrder = 1
    OnClick = btnCerrarClick
  end
end

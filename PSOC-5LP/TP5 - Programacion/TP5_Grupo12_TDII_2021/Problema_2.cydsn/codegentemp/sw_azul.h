/*******************************************************************************
* File Name: sw_azul.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_sw_azul_H) /* Pins sw_azul_H */
#define CY_PINS_sw_azul_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sw_azul_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sw_azul__PORT == 15 && ((sw_azul__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sw_azul_Write(uint8 value);
void    sw_azul_SetDriveMode(uint8 mode);
uint8   sw_azul_ReadDataReg(void);
uint8   sw_azul_Read(void);
void    sw_azul_SetInterruptMode(uint16 position, uint16 mode);
uint8   sw_azul_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sw_azul_SetDriveMode() function.
     *  @{
     */
        #define sw_azul_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sw_azul_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sw_azul_DM_RES_UP          PIN_DM_RES_UP
        #define sw_azul_DM_RES_DWN         PIN_DM_RES_DWN
        #define sw_azul_DM_OD_LO           PIN_DM_OD_LO
        #define sw_azul_DM_OD_HI           PIN_DM_OD_HI
        #define sw_azul_DM_STRONG          PIN_DM_STRONG
        #define sw_azul_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sw_azul_MASK               sw_azul__MASK
#define sw_azul_SHIFT              sw_azul__SHIFT
#define sw_azul_WIDTH              1u

/* Interrupt constants */
#if defined(sw_azul__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sw_azul_SetInterruptMode() function.
     *  @{
     */
        #define sw_azul_INTR_NONE      (uint16)(0x0000u)
        #define sw_azul_INTR_RISING    (uint16)(0x0001u)
        #define sw_azul_INTR_FALLING   (uint16)(0x0002u)
        #define sw_azul_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sw_azul_INTR_MASK      (0x01u) 
#endif /* (sw_azul__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sw_azul_PS                     (* (reg8 *) sw_azul__PS)
/* Data Register */
#define sw_azul_DR                     (* (reg8 *) sw_azul__DR)
/* Port Number */
#define sw_azul_PRT_NUM                (* (reg8 *) sw_azul__PRT) 
/* Connect to Analog Globals */                                                  
#define sw_azul_AG                     (* (reg8 *) sw_azul__AG)                       
/* Analog MUX bux enable */
#define sw_azul_AMUX                   (* (reg8 *) sw_azul__AMUX) 
/* Bidirectional Enable */                                                        
#define sw_azul_BIE                    (* (reg8 *) sw_azul__BIE)
/* Bit-mask for Aliased Register Access */
#define sw_azul_BIT_MASK               (* (reg8 *) sw_azul__BIT_MASK)
/* Bypass Enable */
#define sw_azul_BYP                    (* (reg8 *) sw_azul__BYP)
/* Port wide control signals */                                                   
#define sw_azul_CTL                    (* (reg8 *) sw_azul__CTL)
/* Drive Modes */
#define sw_azul_DM0                    (* (reg8 *) sw_azul__DM0) 
#define sw_azul_DM1                    (* (reg8 *) sw_azul__DM1)
#define sw_azul_DM2                    (* (reg8 *) sw_azul__DM2) 
/* Input Buffer Disable Override */
#define sw_azul_INP_DIS                (* (reg8 *) sw_azul__INP_DIS)
/* LCD Common or Segment Drive */
#define sw_azul_LCD_COM_SEG            (* (reg8 *) sw_azul__LCD_COM_SEG)
/* Enable Segment LCD */
#define sw_azul_LCD_EN                 (* (reg8 *) sw_azul__LCD_EN)
/* Slew Rate Control */
#define sw_azul_SLW                    (* (reg8 *) sw_azul__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sw_azul_PRTDSI__CAPS_SEL       (* (reg8 *) sw_azul__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sw_azul_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sw_azul__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sw_azul_PRTDSI__OE_SEL0        (* (reg8 *) sw_azul__PRTDSI__OE_SEL0) 
#define sw_azul_PRTDSI__OE_SEL1        (* (reg8 *) sw_azul__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sw_azul_PRTDSI__OUT_SEL0       (* (reg8 *) sw_azul__PRTDSI__OUT_SEL0) 
#define sw_azul_PRTDSI__OUT_SEL1       (* (reg8 *) sw_azul__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sw_azul_PRTDSI__SYNC_OUT       (* (reg8 *) sw_azul__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sw_azul__SIO_CFG)
    #define sw_azul_SIO_HYST_EN        (* (reg8 *) sw_azul__SIO_HYST_EN)
    #define sw_azul_SIO_REG_HIFREQ     (* (reg8 *) sw_azul__SIO_REG_HIFREQ)
    #define sw_azul_SIO_CFG            (* (reg8 *) sw_azul__SIO_CFG)
    #define sw_azul_SIO_DIFF           (* (reg8 *) sw_azul__SIO_DIFF)
#endif /* (sw_azul__SIO_CFG) */

/* Interrupt Registers */
#if defined(sw_azul__INTSTAT)
    #define sw_azul_INTSTAT            (* (reg8 *) sw_azul__INTSTAT)
    #define sw_azul_SNAP               (* (reg8 *) sw_azul__SNAP)
    
	#define sw_azul_0_INTTYPE_REG 		(* (reg8 *) sw_azul__0__INTTYPE)
#endif /* (sw_azul__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sw_azul_H */


/* [] END OF FILE */

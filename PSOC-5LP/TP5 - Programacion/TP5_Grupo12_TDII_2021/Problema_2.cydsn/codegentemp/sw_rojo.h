/*******************************************************************************
* File Name: sw_rojo.h  
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

#if !defined(CY_PINS_sw_rojo_H) /* Pins sw_rojo_H */
#define CY_PINS_sw_rojo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sw_rojo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sw_rojo__PORT == 15 && ((sw_rojo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sw_rojo_Write(uint8 value);
void    sw_rojo_SetDriveMode(uint8 mode);
uint8   sw_rojo_ReadDataReg(void);
uint8   sw_rojo_Read(void);
void    sw_rojo_SetInterruptMode(uint16 position, uint16 mode);
uint8   sw_rojo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sw_rojo_SetDriveMode() function.
     *  @{
     */
        #define sw_rojo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sw_rojo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sw_rojo_DM_RES_UP          PIN_DM_RES_UP
        #define sw_rojo_DM_RES_DWN         PIN_DM_RES_DWN
        #define sw_rojo_DM_OD_LO           PIN_DM_OD_LO
        #define sw_rojo_DM_OD_HI           PIN_DM_OD_HI
        #define sw_rojo_DM_STRONG          PIN_DM_STRONG
        #define sw_rojo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sw_rojo_MASK               sw_rojo__MASK
#define sw_rojo_SHIFT              sw_rojo__SHIFT
#define sw_rojo_WIDTH              1u

/* Interrupt constants */
#if defined(sw_rojo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sw_rojo_SetInterruptMode() function.
     *  @{
     */
        #define sw_rojo_INTR_NONE      (uint16)(0x0000u)
        #define sw_rojo_INTR_RISING    (uint16)(0x0001u)
        #define sw_rojo_INTR_FALLING   (uint16)(0x0002u)
        #define sw_rojo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sw_rojo_INTR_MASK      (0x01u) 
#endif /* (sw_rojo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sw_rojo_PS                     (* (reg8 *) sw_rojo__PS)
/* Data Register */
#define sw_rojo_DR                     (* (reg8 *) sw_rojo__DR)
/* Port Number */
#define sw_rojo_PRT_NUM                (* (reg8 *) sw_rojo__PRT) 
/* Connect to Analog Globals */                                                  
#define sw_rojo_AG                     (* (reg8 *) sw_rojo__AG)                       
/* Analog MUX bux enable */
#define sw_rojo_AMUX                   (* (reg8 *) sw_rojo__AMUX) 
/* Bidirectional Enable */                                                        
#define sw_rojo_BIE                    (* (reg8 *) sw_rojo__BIE)
/* Bit-mask for Aliased Register Access */
#define sw_rojo_BIT_MASK               (* (reg8 *) sw_rojo__BIT_MASK)
/* Bypass Enable */
#define sw_rojo_BYP                    (* (reg8 *) sw_rojo__BYP)
/* Port wide control signals */                                                   
#define sw_rojo_CTL                    (* (reg8 *) sw_rojo__CTL)
/* Drive Modes */
#define sw_rojo_DM0                    (* (reg8 *) sw_rojo__DM0) 
#define sw_rojo_DM1                    (* (reg8 *) sw_rojo__DM1)
#define sw_rojo_DM2                    (* (reg8 *) sw_rojo__DM2) 
/* Input Buffer Disable Override */
#define sw_rojo_INP_DIS                (* (reg8 *) sw_rojo__INP_DIS)
/* LCD Common or Segment Drive */
#define sw_rojo_LCD_COM_SEG            (* (reg8 *) sw_rojo__LCD_COM_SEG)
/* Enable Segment LCD */
#define sw_rojo_LCD_EN                 (* (reg8 *) sw_rojo__LCD_EN)
/* Slew Rate Control */
#define sw_rojo_SLW                    (* (reg8 *) sw_rojo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sw_rojo_PRTDSI__CAPS_SEL       (* (reg8 *) sw_rojo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sw_rojo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sw_rojo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sw_rojo_PRTDSI__OE_SEL0        (* (reg8 *) sw_rojo__PRTDSI__OE_SEL0) 
#define sw_rojo_PRTDSI__OE_SEL1        (* (reg8 *) sw_rojo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sw_rojo_PRTDSI__OUT_SEL0       (* (reg8 *) sw_rojo__PRTDSI__OUT_SEL0) 
#define sw_rojo_PRTDSI__OUT_SEL1       (* (reg8 *) sw_rojo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sw_rojo_PRTDSI__SYNC_OUT       (* (reg8 *) sw_rojo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sw_rojo__SIO_CFG)
    #define sw_rojo_SIO_HYST_EN        (* (reg8 *) sw_rojo__SIO_HYST_EN)
    #define sw_rojo_SIO_REG_HIFREQ     (* (reg8 *) sw_rojo__SIO_REG_HIFREQ)
    #define sw_rojo_SIO_CFG            (* (reg8 *) sw_rojo__SIO_CFG)
    #define sw_rojo_SIO_DIFF           (* (reg8 *) sw_rojo__SIO_DIFF)
#endif /* (sw_rojo__SIO_CFG) */

/* Interrupt Registers */
#if defined(sw_rojo__INTSTAT)
    #define sw_rojo_INTSTAT            (* (reg8 *) sw_rojo__INTSTAT)
    #define sw_rojo_SNAP               (* (reg8 *) sw_rojo__SNAP)
    
	#define sw_rojo_0_INTTYPE_REG 		(* (reg8 *) sw_rojo__0__INTTYPE)
#endif /* (sw_rojo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sw_rojo_H */


/* [] END OF FILE */

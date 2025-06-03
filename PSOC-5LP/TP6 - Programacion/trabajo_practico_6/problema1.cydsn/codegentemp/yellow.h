/*******************************************************************************
* File Name: yellow.h  
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

#if !defined(CY_PINS_yellow_H) /* Pins yellow_H */
#define CY_PINS_yellow_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "yellow_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 yellow__PORT == 15 && ((yellow__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    yellow_Write(uint8 value);
void    yellow_SetDriveMode(uint8 mode);
uint8   yellow_ReadDataReg(void);
uint8   yellow_Read(void);
void    yellow_SetInterruptMode(uint16 position, uint16 mode);
uint8   yellow_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the yellow_SetDriveMode() function.
     *  @{
     */
        #define yellow_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define yellow_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define yellow_DM_RES_UP          PIN_DM_RES_UP
        #define yellow_DM_RES_DWN         PIN_DM_RES_DWN
        #define yellow_DM_OD_LO           PIN_DM_OD_LO
        #define yellow_DM_OD_HI           PIN_DM_OD_HI
        #define yellow_DM_STRONG          PIN_DM_STRONG
        #define yellow_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define yellow_MASK               yellow__MASK
#define yellow_SHIFT              yellow__SHIFT
#define yellow_WIDTH              1u

/* Interrupt constants */
#if defined(yellow__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in yellow_SetInterruptMode() function.
     *  @{
     */
        #define yellow_INTR_NONE      (uint16)(0x0000u)
        #define yellow_INTR_RISING    (uint16)(0x0001u)
        #define yellow_INTR_FALLING   (uint16)(0x0002u)
        #define yellow_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define yellow_INTR_MASK      (0x01u) 
#endif /* (yellow__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define yellow_PS                     (* (reg8 *) yellow__PS)
/* Data Register */
#define yellow_DR                     (* (reg8 *) yellow__DR)
/* Port Number */
#define yellow_PRT_NUM                (* (reg8 *) yellow__PRT) 
/* Connect to Analog Globals */                                                  
#define yellow_AG                     (* (reg8 *) yellow__AG)                       
/* Analog MUX bux enable */
#define yellow_AMUX                   (* (reg8 *) yellow__AMUX) 
/* Bidirectional Enable */                                                        
#define yellow_BIE                    (* (reg8 *) yellow__BIE)
/* Bit-mask for Aliased Register Access */
#define yellow_BIT_MASK               (* (reg8 *) yellow__BIT_MASK)
/* Bypass Enable */
#define yellow_BYP                    (* (reg8 *) yellow__BYP)
/* Port wide control signals */                                                   
#define yellow_CTL                    (* (reg8 *) yellow__CTL)
/* Drive Modes */
#define yellow_DM0                    (* (reg8 *) yellow__DM0) 
#define yellow_DM1                    (* (reg8 *) yellow__DM1)
#define yellow_DM2                    (* (reg8 *) yellow__DM2) 
/* Input Buffer Disable Override */
#define yellow_INP_DIS                (* (reg8 *) yellow__INP_DIS)
/* LCD Common or Segment Drive */
#define yellow_LCD_COM_SEG            (* (reg8 *) yellow__LCD_COM_SEG)
/* Enable Segment LCD */
#define yellow_LCD_EN                 (* (reg8 *) yellow__LCD_EN)
/* Slew Rate Control */
#define yellow_SLW                    (* (reg8 *) yellow__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define yellow_PRTDSI__CAPS_SEL       (* (reg8 *) yellow__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define yellow_PRTDSI__DBL_SYNC_IN    (* (reg8 *) yellow__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define yellow_PRTDSI__OE_SEL0        (* (reg8 *) yellow__PRTDSI__OE_SEL0) 
#define yellow_PRTDSI__OE_SEL1        (* (reg8 *) yellow__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define yellow_PRTDSI__OUT_SEL0       (* (reg8 *) yellow__PRTDSI__OUT_SEL0) 
#define yellow_PRTDSI__OUT_SEL1       (* (reg8 *) yellow__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define yellow_PRTDSI__SYNC_OUT       (* (reg8 *) yellow__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(yellow__SIO_CFG)
    #define yellow_SIO_HYST_EN        (* (reg8 *) yellow__SIO_HYST_EN)
    #define yellow_SIO_REG_HIFREQ     (* (reg8 *) yellow__SIO_REG_HIFREQ)
    #define yellow_SIO_CFG            (* (reg8 *) yellow__SIO_CFG)
    #define yellow_SIO_DIFF           (* (reg8 *) yellow__SIO_DIFF)
#endif /* (yellow__SIO_CFG) */

/* Interrupt Registers */
#if defined(yellow__INTSTAT)
    #define yellow_INTSTAT            (* (reg8 *) yellow__INTSTAT)
    #define yellow_SNAP               (* (reg8 *) yellow__SNAP)
    
	#define yellow_0_INTTYPE_REG 		(* (reg8 *) yellow__0__INTTYPE)
#endif /* (yellow__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_yellow_H */


/* [] END OF FILE */

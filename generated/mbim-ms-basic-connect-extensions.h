
/* GENERATED CODE... DO NOT EDIT */

/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2013 - 2018 Aleksander Morgado <aleksander@aleksander.es>
 */


#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>

#include "mbim-message.h"
#include "mbim-device.h"
#include "mbim-enums.h"

#ifndef __LIBMBIM_GLIB_MBIM_MS_BASIC_CONNECT_EXTENSIONS__
#define __LIBMBIM_GLIB_MBIM_MS_BASIC_CONNECT_EXTENSIONS__

G_BEGIN_DECLS

/*****************************************************************************/
/* Struct: MbimPcoValue */

/**
 * MbimPcoValue:
 * @session_id: a #guint32.
 * @pco_data_size: a #guint32.
 * @pco_data_type: a #guint32.
 * @pco_data_buffer: an array of #guint8 values.
 *
 * Since: 1.18
 */
typedef struct {
    guint32 session_id;
    guint32 pco_data_size;
    guint32 pco_data_type;
    guint8 *pco_data_buffer;
} MbimPcoValue;

/**
 * mbim_pco_value_free:
 * @var: a #MbimPcoValue.
 *
 * Frees the memory allocated for the #MbimPcoValue.
 *
 * Since: 1.18
 */
void mbim_pco_value_free (MbimPcoValue *var);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MbimPcoValue, mbim_pco_value_free)

/*****************************************************************************/
/* Struct: MbimLteAttachConfiguration */

/**
 * MbimLteAttachConfiguration:
 * @ip_type: a #guint32.
 * @roaming: a #guint32.
 * @source: a #guint32.
 * @access_string: a string.
 * @user_name: a string.
 * @password: a string.
 * @compression: a #guint32.
 * @auth_protocol: a #guint32.
 *
 * Since: 1.18
 */
typedef struct {
    guint32 ip_type;
    guint32 roaming;
    guint32 source;
    gchar *access_string;
    gchar *user_name;
    gchar *password;
    guint32 compression;
    guint32 auth_protocol;
} MbimLteAttachConfiguration;

/**
 * MbimLteAttachConfigurationArray:
 *
 * A NULL-terminated array of MbimLteAttachConfiguration elements.
 *
 * Since: 1.24
 */
typedef MbimLteAttachConfiguration *MbimLteAttachConfigurationArray;
/**
 * mbim_lte_attach_configuration_array_free:
 * @array: a #NULL terminated array of #MbimLteAttachConfiguration structs.
 *
 * Frees the memory allocated for the array of #MbimLteAttachConfigurations.
 *
 * Since: 1.18
 */
void mbim_lte_attach_configuration_array_free (MbimLteAttachConfigurationArray *array);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MbimLteAttachConfigurationArray, mbim_lte_attach_configuration_array_free)

/*****************************************************************************/
/* Struct: MbimLteAttachStatus */

/**
 * MbimLteAttachStatus:
 * @lte_attach_state: a #guint32.
 * @ip_type: a #guint32.
 * @access_string: a string.
 * @user_name: a string.
 * @password: a string.
 * @compression: a #guint32.
 * @auth_protocol: a #guint32.
 *
 * Since: 1.18
 */
typedef struct {
    guint32 lte_attach_state;
    guint32 ip_type;
    gchar *access_string;
    gchar *user_name;
    gchar *password;
    guint32 compression;
    guint32 auth_protocol;
} MbimLteAttachStatus;

/**
 * mbim_lte_attach_status_free:
 * @var: a #MbimLteAttachStatus.
 *
 * Frees the memory allocated for the #MbimLteAttachStatus.
 *
 * Since: 1.18
 */
void mbim_lte_attach_status_free (MbimLteAttachStatus *var);
G_DEFINE_AUTOPTR_CLEANUP_FUNC (MbimLteAttachStatus, mbim_lte_attach_status_free)

/*****************************************************************************/
/* Message (Query): MBIM Message Ms Basic Connect Extensions PCO */

/**
 * mbim_message_ms_basic_connect_extensions_pco_query_new:
 * @pco_value: (in): the 'PcoValue' field, given as a #MbimPcoValue.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'PCO' query command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.18
 */
MbimMessage *mbim_message_ms_basic_connect_extensions_pco_query_new (
    const MbimPcoValue *pco_value,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Ms Basic Connect Extensions PCO */

/**
 * mbim_message_ms_basic_connect_extensions_pco_response_parse:
 * @message: the #MbimMessage.
 * @out_pco_value: (out)(optional)(transfer full): return location for a newly allocated #MbimPcoValue, or %NULL if the 'PcoValue' field is not needed. Free the returned value with mbim_pco_value_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'PCO' response command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_pco_response_parse (
    const MbimMessage *message,
    MbimPcoValue **out_pco_value,
    GError **error);

/*****************************************************************************/
/* Message (Notification): MBIM Message Ms Basic Connect Extensions PCO */

/**
 * mbim_message_ms_basic_connect_extensions_pco_notification_parse:
 * @message: the #MbimMessage.
 * @out_pco_value: (out)(optional)(transfer full): return location for a newly allocated #MbimPcoValue, or %NULL if the 'PcoValue' field is not needed. Free the returned value with mbim_pco_value_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'PCO' notification command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_pco_notification_parse (
    const MbimMessage *message,
    MbimPcoValue **out_pco_value,
    GError **error);

/*****************************************************************************/
/* Message (Query): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_configuration_query_new:
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Lte Attach Configuration' query command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.18
 */
MbimMessage *mbim_message_ms_basic_connect_extensions_lte_attach_configuration_query_new (
    GError **error);

/*****************************************************************************/
/* Message (Set): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_configuration_set_new:
 * @operation: (in): the 'Operation' field, given as a #MbimLteAttachContextOperation.
 * @configuration_count: (in): the 'ConfigurationCount' field, given as a #guint32.
 * @configurations: (in): the 'Configurations' field, given as an array of #MbimLteAttachConfigurations.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Lte Attach Configuration' set command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.18
 */
MbimMessage *mbim_message_ms_basic_connect_extensions_lte_attach_configuration_set_new (
    MbimLteAttachContextOperation operation,
    guint32 configuration_count,
    const MbimLteAttachConfiguration *const *configurations,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_configuration_response_parse:
 * @message: the #MbimMessage.
 * @out_configuration_count: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'ConfigurationCount' field is not needed.
 * @out_configurations: (out)(optional)(transfer full)(array zero-terminated=1)(element-type MbimLteAttachConfiguration): return location for a newly allocated array of #MbimLteAttachConfigurations, or %NULL if the 'Configurations' field is not needed. Free the returned value with mbim_lte_attach_configuration_array_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Lte Attach Configuration' response command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_lte_attach_configuration_response_parse (
    const MbimMessage *message,
    guint32 *out_configuration_count,
    MbimLteAttachConfigurationArray **out_configurations,
    GError **error);

/*****************************************************************************/
/* Message (Notification): MBIM Message Ms Basic Connect Extensions Lte Attach Configuration */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_configuration_notification_parse:
 * @message: the #MbimMessage.
 * @out_configuration_count: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'ConfigurationCount' field is not needed.
 * @out_configurations: (out)(optional)(transfer full)(array zero-terminated=1)(element-type MbimLteAttachConfiguration): return location for a newly allocated array of #MbimLteAttachConfigurations, or %NULL if the 'Configurations' field is not needed. Free the returned value with mbim_lte_attach_configuration_array_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Lte Attach Configuration' notification command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_lte_attach_configuration_notification_parse (
    const MbimMessage *message,
    guint32 *out_configuration_count,
    MbimLteAttachConfigurationArray **out_configurations,
    GError **error);

/*****************************************************************************/
/* Message (Query): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_status_query_new:
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Lte Attach Status' query command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.18
 */
MbimMessage *mbim_message_ms_basic_connect_extensions_lte_attach_status_query_new (
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_status_response_parse:
 * @message: the #MbimMessage.
 * @out_lte_attach_status: (out)(optional)(transfer full): return location for a newly allocated #MbimLteAttachStatus, or %NULL if the 'LteAttachStatus' field is not needed. Free the returned value with mbim_lte_attach_status_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Lte Attach Status' response command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_lte_attach_status_response_parse (
    const MbimMessage *message,
    MbimLteAttachStatus **out_lte_attach_status,
    GError **error);

/*****************************************************************************/
/* Message (Notification): MBIM Message Ms Basic Connect Extensions Lte Attach Status */

/**
 * mbim_message_ms_basic_connect_extensions_lte_attach_status_notification_parse:
 * @message: the #MbimMessage.
 * @out_lte_attach_status: (out)(optional)(transfer full): return location for a newly allocated #MbimLteAttachStatus, or %NULL if the 'LteAttachStatus' field is not needed. Free the returned value with mbim_lte_attach_status_free().
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Lte Attach Status' notification command in the 'Ms Basic Connect Extensions' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.18
 */
gboolean mbim_message_ms_basic_connect_extensions_lte_attach_status_notification_parse (
    const MbimMessage *message,
    MbimLteAttachStatus **out_lte_attach_status,
    GError **error);

/*****************************************************************************/
/* Service helper for printable fields */

#if defined (LIBMBIM_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *
__mbim_message_ms_basic_connect_extensions_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error);

#endif

G_END_DECLS

#endif /* __LIBMBIM_GLIB_MBIM_MS_BASIC_CONNECT_EXTENSIONS__ */

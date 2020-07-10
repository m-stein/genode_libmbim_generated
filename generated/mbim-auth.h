
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

#ifndef __LIBMBIM_GLIB_MBIM_AUTH__
#define __LIBMBIM_GLIB_MBIM_AUTH__

G_BEGIN_DECLS

/*****************************************************************************/
/* Message (Query): MBIM Message Auth Aka */

/**
 * mbim_message_auth_aka_query_new:
 * @rand: (in)(element-type guint8)(array fixed-size=16): the 'Rand' field, given as an array of 16 #guint8 values.
 * @autn: (in)(element-type guint8)(array fixed-size=16): the 'Autn' field, given as an array of 16 #guint8 values.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Aka' query command in the 'Auth' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.4
 */
MbimMessage *mbim_message_auth_aka_query_new (
    const guint8 *rand,
    const guint8 *autn,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Auth Aka */

/**
 * mbim_message_auth_aka_response_parse:
 * @message: the #MbimMessage.
 * @out_res: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_res_len: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'ResLen' field is not needed.
 * @out_integrating_key: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_ciphering_key: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_auts: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=14): return location for an array of 14 #guint8 values. Do not free the returned value, it is owned by @message.
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Aka' response command in the 'Auth' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.4
 */
gboolean mbim_message_auth_aka_response_parse (
    const MbimMessage *message,
    const guint8 **out_res,
    guint32 *out_res_len,
    const guint8 **out_integrating_key,
    const guint8 **out_ciphering_key,
    const guint8 **out_auts,
    GError **error);

/*****************************************************************************/
/* Message (Query): MBIM Message Auth Akap */

/**
 * mbim_message_auth_akap_query_new:
 * @rand: (in)(element-type guint8)(array fixed-size=16): the 'Rand' field, given as an array of 16 #guint8 values.
 * @autn: (in)(element-type guint8)(array fixed-size=16): the 'Autn' field, given as an array of 16 #guint8 values.
 * @network_name: (in): the 'NetworkName' field, given as a string.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Akap' query command in the 'Auth' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.4
 */
MbimMessage *mbim_message_auth_akap_query_new (
    const guint8 *rand,
    const guint8 *autn,
    const gchar *network_name,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Auth Akap */

/**
 * mbim_message_auth_akap_response_parse:
 * @message: the #MbimMessage.
 * @out_res: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_res_len: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'ResLen' field is not needed.
 * @out_integrating_key: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_ciphering_key: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=16): return location for an array of 16 #guint8 values. Do not free the returned value, it is owned by @message.
 * @out_auts: (out)(optional)(transfer none)(element-type guint8)(array fixed-size=14): return location for an array of 14 #guint8 values. Do not free the returned value, it is owned by @message.
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Akap' response command in the 'Auth' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.4
 */
gboolean mbim_message_auth_akap_response_parse (
    const MbimMessage *message,
    const guint8 **out_res,
    guint32 *out_res_len,
    const guint8 **out_integrating_key,
    const guint8 **out_ciphering_key,
    const guint8 **out_auts,
    GError **error);

/*****************************************************************************/
/* Message (Query): MBIM Message Auth Sim */

/**
 * mbim_message_auth_sim_query_new:
 * @rand1: (in)(element-type guint8)(array fixed-size=16): the 'Rand1' field, given as an array of 16 #guint8 values.
 * @rand2: (in)(element-type guint8)(array fixed-size=16): the 'Rand2' field, given as an array of 16 #guint8 values.
 * @rand3: (in)(element-type guint8)(array fixed-size=16): the 'Rand3' field, given as an array of 16 #guint8 values.
 * @n: (in): the 'N' field, given as a #guint32.
 * @error: return location for error or %NULL.
 *
 * Create a new request for the 'Sim' query command in the 'Auth' service.
 *
 * Returns: a newly allocated #MbimMessage, which should be freed with mbim_message_unref().
 *
 * Since: 1.4
 */
MbimMessage *mbim_message_auth_sim_query_new (
    const guint8 *rand1,
    const guint8 *rand2,
    const guint8 *rand3,
    guint32 n,
    GError **error);

/*****************************************************************************/
/* Message (Response): MBIM Message Auth Sim */

/**
 * mbim_message_auth_sim_response_parse:
 * @message: the #MbimMessage.
 * @out_sres1: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'Sres1' field is not needed.
 * @out_kc1: (out)(optional)(transfer none): return location for a #guint64, or %NULL if the 'Kc1' field is not needed.
 * @out_sres2: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'Sres2' field is not needed.
 * @out_kc2: (out)(optional)(transfer none): return location for a #guint64, or %NULL if the 'Kc2' field is not needed.
 * @out_sres3: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'Sres3' field is not needed.
 * @out_kc3: (out)(optional)(transfer none): return location for a #guint64, or %NULL if the 'Kc3' field is not needed.
 * @out_n: (out)(optional)(transfer none): return location for a #guint32, or %NULL if the 'N' field is not needed.
 * @error: return location for error or %NULL.
 *
 * Parses and returns parameters of the 'Sim' response command in the 'Auth' service.
 *
 * Returns: %TRUE if the message was correctly parsed, %FALSE if @error is set.
 *
 * Since: 1.4
 */
gboolean mbim_message_auth_sim_response_parse (
    const MbimMessage *message,
    guint32 *out_sres1,
    guint64 *out_kc1,
    guint32 *out_sres2,
    guint64 *out_kc2,
    guint32 *out_sres3,
    guint64 *out_kc3,
    guint32 *out_n,
    GError **error);

/*****************************************************************************/
/* Service helper for printable fields */

#if defined (LIBMBIM_GLIB_COMPILATION)

G_GNUC_INTERNAL
gchar *
__mbim_message_auth_get_printable_fields (
    const MbimMessage *message,
    const gchar *line_prefix,
    GError **error);

#endif

G_END_DECLS

#endif /* __LIBMBIM_GLIB_MBIM_AUTH__ */

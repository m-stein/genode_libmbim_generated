
/* This file is generated by glib-mkenums, do not modify it. This code is licensed under the same license as the containing project. Note that it links to GLib, so must comply with the LGPL linking clauses. */

#include "mbim-errors.h"
#include "mbim-error-types.h"

#include <gio/gio.h>
/* enumerations from "../../../src/libmbim-glib/mbim-errors.h" */

#define ERROR_PREFIX MBIM_CORE_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_core_error_entries[] = {
    { MBIM_CORE_ERROR_FAILED, ERROR_PREFIX ".Failed" },
    { MBIM_CORE_ERROR_WRONG_STATE, ERROR_PREFIX ".WrongState" },
    { MBIM_CORE_ERROR_TIMEOUT, ERROR_PREFIX ".Timeout" },
    { MBIM_CORE_ERROR_INVALID_ARGS, ERROR_PREFIX ".InvalidArgs" },
    { MBIM_CORE_ERROR_INVALID_MESSAGE, ERROR_PREFIX ".InvalidMessage" },
    { MBIM_CORE_ERROR_UNSUPPORTED, ERROR_PREFIX ".Unsupported" },
    { MBIM_CORE_ERROR_ABORTED, ERROR_PREFIX ".Aborted" },
    { MBIM_CORE_ERROR_UNKNOWN_STATE, ERROR_PREFIX ".UnknownState" },
};
#undef ERROR_PREFIX

GQuark
mbim_core_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_core_error_quark",
                                            &quark_volatile,
                                            mbim_core_error_entries,
                                            G_N_ELEMENTS (mbim_core_error_entries));

    return (GQuark) quark_volatile;
}

#define ERROR_PREFIX MBIM_PROTOCOL_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_protocol_error_entries[] = {
    { MBIM_PROTOCOL_ERROR_INVALID, ERROR_PREFIX ".Invalid" },
    { MBIM_PROTOCOL_ERROR_TIMEOUT_FRAGMENT, ERROR_PREFIX ".TimeoutFragment" },
    { MBIM_PROTOCOL_ERROR_FRAGMENT_OUT_OF_SEQUENCE, ERROR_PREFIX ".FragmentOutOfSequence" },
    { MBIM_PROTOCOL_ERROR_LENGTH_MISMATCH, ERROR_PREFIX ".LengthMismatch" },
    { MBIM_PROTOCOL_ERROR_DUPLICATED_TID, ERROR_PREFIX ".DuplicatedTid" },
    { MBIM_PROTOCOL_ERROR_NOT_OPENED, ERROR_PREFIX ".NotOpened" },
    { MBIM_PROTOCOL_ERROR_UNKNOWN, ERROR_PREFIX ".Unknown" },
    { MBIM_PROTOCOL_ERROR_CANCEL, ERROR_PREFIX ".Cancel" },
    { MBIM_PROTOCOL_ERROR_MAX_TRANSFER, ERROR_PREFIX ".MaxTransfer" },
};
#undef ERROR_PREFIX

GQuark
mbim_protocol_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_protocol_error_quark",
                                            &quark_volatile,
                                            mbim_protocol_error_entries,
                                            G_N_ELEMENTS (mbim_protocol_error_entries));

    return (GQuark) quark_volatile;
}

#define ERROR_PREFIX MBIM_STATUS_ERROR_DBUS_PREFIX
static const GDBusErrorEntry mbim_status_error_entries[] = {
    { MBIM_STATUS_ERROR_NONE, ERROR_PREFIX ".None" },
    { MBIM_STATUS_ERROR_BUSY, ERROR_PREFIX ".Busy" },
    { MBIM_STATUS_ERROR_FAILURE, ERROR_PREFIX ".Failure" },
    { MBIM_STATUS_ERROR_SIM_NOT_INSERTED, ERROR_PREFIX ".SimNotInserted" },
    { MBIM_STATUS_ERROR_BAD_SIM, ERROR_PREFIX ".BadSim" },
    { MBIM_STATUS_ERROR_PIN_REQUIRED, ERROR_PREFIX ".PinRequired" },
    { MBIM_STATUS_ERROR_PIN_DISABLED, ERROR_PREFIX ".PinDisabled" },
    { MBIM_STATUS_ERROR_NOT_REGISTERED, ERROR_PREFIX ".NotRegistered" },
    { MBIM_STATUS_ERROR_PROVIDERS_NOT_FOUND, ERROR_PREFIX ".ProvidersNotFound" },
    { MBIM_STATUS_ERROR_NO_DEVICE_SUPPORT, ERROR_PREFIX ".NoDeviceSupport" },
    { MBIM_STATUS_ERROR_PROVIDER_NOT_VISIBLE, ERROR_PREFIX ".ProviderNotVisible" },
    { MBIM_STATUS_ERROR_DATA_CLASS_NOT_AVAILABLE, ERROR_PREFIX ".DataClassNotAvailable" },
    { MBIM_STATUS_ERROR_PACKET_SERVICE_DETACHED, ERROR_PREFIX ".PacketServiceDetached" },
    { MBIM_STATUS_ERROR_MAX_ACTIVATED_CONTEXTS, ERROR_PREFIX ".MaxActivatedContexts" },
    { MBIM_STATUS_ERROR_NOT_INITIALIZED, ERROR_PREFIX ".NotInitialized" },
    { MBIM_STATUS_ERROR_VOICE_CALL_IN_PROGRESS, ERROR_PREFIX ".VoiceCallInProgress" },
    { MBIM_STATUS_ERROR_CONTEXT_NOT_ACTIVATED, ERROR_PREFIX ".ContextNotActivated" },
    { MBIM_STATUS_ERROR_SERVICE_NOT_ACTIVATED, ERROR_PREFIX ".ServiceNotActivated" },
    { MBIM_STATUS_ERROR_INVALID_ACCESS_STRING, ERROR_PREFIX ".InvalidAccessString" },
    { MBIM_STATUS_ERROR_INVALID_USER_NAME_PWD, ERROR_PREFIX ".InvalidUserNamePwd" },
    { MBIM_STATUS_ERROR_RADIO_POWER_OFF, ERROR_PREFIX ".RadioPowerOff" },
    { MBIM_STATUS_ERROR_INVALID_PARAMETERS, ERROR_PREFIX ".InvalidParameters" },
    { MBIM_STATUS_ERROR_READ_FAILURE, ERROR_PREFIX ".ReadFailure" },
    { MBIM_STATUS_ERROR_WRITE_FAILURE, ERROR_PREFIX ".WriteFailure" },
    { MBIM_STATUS_ERROR_NO_PHONEBOOK, ERROR_PREFIX ".NoPhonebook" },
    { MBIM_STATUS_ERROR_PARAMETER_TOO_LONG, ERROR_PREFIX ".ParameterTooLong" },
    { MBIM_STATUS_ERROR_STK_BUSY, ERROR_PREFIX ".StkBusy" },
    { MBIM_STATUS_ERROR_OPERATION_NOT_ALLOWED, ERROR_PREFIX ".OperationNotAllowed" },
    { MBIM_STATUS_ERROR_MEMORY_FAILURE, ERROR_PREFIX ".MemoryFailure" },
    { MBIM_STATUS_ERROR_INVALID_MEMORY_INDEX, ERROR_PREFIX ".InvalidMemoryIndex" },
    { MBIM_STATUS_ERROR_MEMORY_FULL, ERROR_PREFIX ".MemoryFull" },
    { MBIM_STATUS_ERROR_FILTER_NOT_SUPPORTED, ERROR_PREFIX ".FilterNotSupported" },
    { MBIM_STATUS_ERROR_DSS_INSTANCE_LIMIT, ERROR_PREFIX ".DssInstanceLimit" },
    { MBIM_STATUS_ERROR_INVALID_DEVICE_SERVICE_OPERATION, ERROR_PREFIX ".InvalidDeviceServiceOperation" },
    { MBIM_STATUS_ERROR_AUTH_INCORRECT_AUTN, ERROR_PREFIX ".AuthIncorrectAuth" },
    { MBIM_STATUS_ERROR_AUTH_SYNC_FAILURE, ERROR_PREFIX ".AuthSyncFailure" },
    { MBIM_STATUS_ERROR_AUTH_AMF_NOT_SET, ERROR_PREFIX ".AuthAmfNotSet" },
    { MBIM_STATUS_ERROR_CONTEXT_NOT_SUPPORTED, ERROR_PREFIX ".ContextNotSupported" },
    { MBIM_STATUS_ERROR_SMS_UNKNOWN_SMSC_ADDRESS, ERROR_PREFIX ".SmsUnknownSmscAddress" },
    { MBIM_STATUS_ERROR_SMS_NETWORK_TIMEOUT, ERROR_PREFIX ".SmsNetworkTimeout" },
    { MBIM_STATUS_ERROR_SMS_LANG_NOT_SUPPORTED, ERROR_PREFIX ".SmsLangNotSupported" },
    { MBIM_STATUS_ERROR_SMS_ENCODING_NOT_SUPPORTED, ERROR_PREFIX ".SmsEncodingNotSupported" },
    { MBIM_STATUS_ERROR_SMS_FORMAT_NOT_SUPPORTED, ERROR_PREFIX ".SmsFormatNotSupported" },
};
#undef ERROR_PREFIX

GQuark
mbim_status_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    if (!quark_volatile)
        g_dbus_error_register_error_domain ("mbim_status_error_quark",
                                            &quark_volatile,
                                            mbim_status_error_entries,
                                            G_N_ELEMENTS (mbim_status_error_entries));

    return (GQuark) quark_volatile;
}

/* Generated data ends here */

